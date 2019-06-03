#include <stdio.h>
FILE* fd;
#define FILE_NAME "student.dat"

struct Person {
  int id;
  char first_name[MAX_SIZE];
  char last_name[MAX_SIZE];
  int age;
};

int main(int argc, char const *argv[]) {

  struct Person p[CACHE_SIZE];

  int id;
  fread(&id, sizeof(id), 1, fd);
  int n = fread(p, sizeof(struct Person), id, fd);
  printf("%d items read\n", n);

  fclose(fd);
  return 0;
}
