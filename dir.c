#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>


int main() {
  int size = 0;
  struct dirent *entry;
  DIR* d = opendir(".");
  entry = readdir(d);
  printf("Directories: \n");
  struct stat sb;
  while (entry) {
    stat(entry -> d_name, &sb);
    size += sb.st_size;
    if (entry -> d_type == DT_DIR) printf("%s\n", entry -> d_name);
    entry = readdir(d);
    }
  d = opendir(".");
  entry = readdir(d);
  printf("Regular Files:\n");
  while (entry) {
    if (entry -> d_type == DT_REG) printf("%s\n", entry -> d_name);
    entry = readdir(d);
  }
  printf ("Total Size: %d\n", size);
  return 0;
}
