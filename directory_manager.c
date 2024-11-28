#include "include/directory_manager.h"
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

void list_directory(const char *path) {
  DIR *dir;
  struct dirent *ent;

  if ((dir = opendir(path)) == NULL) {
    perror("Error opening directory");
    return;
  }

  printf("%s", path);
  while ((ent = readdir(dir)) != NULL) {
    if (ent->d_type == DT_DIR) {
      printf("%s/\n", ent->d_name);
    } else {
      printf("%s\n", ent->d_name);
    }
  }
  closedir(dir);
}

int create_directory(const char *path, const char *dir_name) {
  char full_path[256];
  sprintf(full_path, "%s/%s", path, dir_name);
  int status = mkdir(full_path, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

  if (status == 0) {
    printf("Directory '%s' created successfully at '%s'.\n", dir_name, path);
  } else {
    perror("Error creating directory");
  }
  return status;
}

int remove_directory(const char *path) {
  struct stat sb;
  if (stat(path, &sb) == -1) {
    perror("stat");
    return -1;
  }
  if (S_ISDIR(sb.st_mode)) {
    return rmdir(path);
  }
  return unlink(path);
}
