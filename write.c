#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>
int main(int argc, char* argv[]){
clock_t start = clock(),diff;
int fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC), n;
int fd_read = open("read.txt", 0);
unsigned int buffer_size = atoi(argv[3]);
unsigned int buffer[buffer_size];
unsigned int block_count = atoi(argv[2]);
while((n = read(fd_read, buffer, buffer_size*sizeof(unsigned int))) > 0){
  write(fd, buffer, buffer_size);
  }
close(fd);
diff = clock() - start;
int msec = diff * 1000 / CLOCKS_PER_SEC;
double time = msec/1000.0;
printf("Time taken to run is %f seconds\n", time);
return 0;
}
