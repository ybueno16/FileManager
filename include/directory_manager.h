#ifndef DIRECTORY_MANAGER_H
#define DIRECTORY_MANAGER_H

void list_directory(const char *path);
int create_directory(const char *path, const char *dir_name);
int remove_directory(const char *path);

#endif
