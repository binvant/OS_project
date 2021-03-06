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
	int msec, block_count = 1;
	unsigned int buffer_size = 30000;
	buffer_size = ceil(buffer_size/4);
	unsigned int result = 0;
	int fd = open(argv[1], 0), n;
	unsigned int buffer[buffer_size];
	while((n = read(fd, buffer, buffer_size*sizeof(unsigned int))) > 0){
  result ^= xorbuf(buffer, ceil(n/4));
		block_count++;
	}
	close(fd);
	diff = (clock() - start);
  printf("block count %d\n",block_count);
	msec = (diff * 1000 / CLOCKS_PER_SEC);
  double time = msec/1000.0;
  printf("Time taken to run is %f seconds\n", time);
  double x = (double)(block_count*buffer_size*4);
  double mb= x/1048576.0;
  double mbpersec = mb/time;
	printf("Speed in Megabytes per second is %lf MiB/s \n", mbpersec);
	printf("XOR result is %08x\n", result);
	return 0;
}
