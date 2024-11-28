#include "include/directory_manager.h"
#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]) {
  if (argc < 1) {
    printf("No arguments provided\n");
    return 0;
  }
  if (strcmp(argv[1], "myls") == 0) {
    list_directory(argv[2]);
  }
  if (strcmp(argv[1], "mymkdir") == 0) {
    create_directory(argv[2], argv[3]);
  }
  if (strcmp(argv[1], "myrm") == 0) {
    remove_directory(argv[2]);
  }
  return 0;
}
