#include <stdio.h>
#include <sys/stat.h>
FILE* fd;
#define FILE_NAME "student.dat"
#define MAX_SIZE 64

struct Person {
  int id;
  char first_name[MAX_SIZE];
  char last_name[MAX_SIZE];
  int age;
};

long int findSize(const char *file_name){
  struct stat st;
  if(stat(file_name, &st) == 0){
    return st.st_size;
  } else {
    return -1;
  }
}

int main(int argc, char const *argv[]) {
  fd = fopen(FILE_NAME, "a+");
  struct Person p;

  printf("Enter your first name: ");
  scanf("%s", p.first_name);
  printf("Enter your last name: ");
  scanf("%s", p.last_name);
  printf("Enter your age: ");
  scanf("%d", &(p.age));

  fwrite(&p, sizeof(struct Person), 1, fd);
  long int size = findSize(FILE_NAME);
  fseek(fd, -size, SEEK_END);
  int id;
  fread(&id, sizeof(id), 1, fd);
  id++;
  fwrite(&id, sizeof(id), 1, fd);
  fclose(fd);
  return 0;
}
