#include "include/directory_manager.h"
#include <string.h>
int main(int argc, char *argv[]) {
  if (argc > 1 && strcmp(argv[1], "myls") == 0) {
    list_directory(argv[2]);
  }
  return 0;
}
