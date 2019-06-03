#include <stdio.h>
FILE* fd;
#define FILE_NAME "student.dat"

int main(int argc, char const *argv[]) {
  fd = fopen(FILE_NAME, "w");
  int id = 1;
  fwrite(&id, sizeof(id), 1, fd);
  fclose(fd);
  return 0;
}
