#include "include/directory_manager.h"
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

void list_directory(const char *path) {
  DIR *dir;
  struct dirent *ent;

  if ((dir = opendir(path)) == NULL) {
    perror("Erro ao abrir o directório");
    return;
  }

  printf("Os arquivos e diretórios em %s:\n", path);
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
