#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>
int main(int argc, char* argv[]){
int fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC), n;
int fd_read = open("project.c", 0);
unsigned int buffer_size = atoi(argv[3]);
unsigned int buffer[buffer_size];
unsigned int block_count = atoi(argv[2]);
while((n = read(fd_read, buffer, buffer_size*sizeof(unsigned int))) > 0){
  write(fd, buffer, buffer_size);
  }
close(fd);
return 0;
}
