#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>
unsigned int xorbuf(unsigned int *buffer, int size) {
    unsigned int result = 0;
    for (int i = 0; i < size; i++) {
        result ^= buffer[i];
    }
    return result;
}
int main(int argc, char* argv[]){
	clock_t start = clock(),diff;
	int msec, block_count = 0;
	unsigned int buffer_size = atoi(argv[3]);
	buffer_size = ceil(buffer_size/4);
	unsigned int result = 0;
  if(buffer_size == 0){

    buffer_size =1;
  }
	int fd = open(argv[1], O_RDWR | O_CREAT | O_APPEND), n;
	unsigned int buffer[buffer_size];
  //int given_block = atoi(argv[4]);
  int count=0;
	while((n = read(fd, buffer, buffer_size*sizeof(unsigned int))) > 0){
  result ^= xorbuf(buffer, ceil(n/4));
		block_count++;
    clock_t bin = clock() - start;
    int msec2 = bin * 1000 / CLOCKS_PER_SEC;
    count++;
    if (msec2 > 5000){
      printf("For a block count of %d the file size read is %d bytes \n", block_count,block_count*buffer_size);
      count=
      break;
    }


	}
  printf("Block count: %d\n", block_count);
	close(fd);
	diff = clock() - start;
	msec = diff * 1000 / CLOCKS_PER_SEC;
  double time = msec/1000.0;
  printf("Time taken to run is %f seconds\n", time);
  double mb= (block_count*buffer_size)/1048576.0;
	printf("Speed in Megabytes per second is %f MiB/s \n", mb/time);
	printf("XOR result is %08x\n", result);
	return 0;
}
