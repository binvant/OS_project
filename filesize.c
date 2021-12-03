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
	clock_t start = clock(),diff, bin;
	int msec, msec2, block_count = 1;
	unsigned int buffer_size = 10000;
	buffer_size = ceil(buffer_size/4);
	unsigned int result = 0;
	int fd = open(argv[1], 0), n;
	unsigned int buffer[buffer_size];
	while((n = read(fd, buffer, buffer_size*sizeof(unsigned int))) > 0){
  result ^= xorbuf(buffer, ceil(n/4));
    bin = clock() - start;
		msec2 = bin * 1000 / CLOCKS_PER_SEC;
		//printf("%d \n", block_count);
		//printf("msec2 %d\n", msec2);

		 if(msec2 % 1000 > argv[2][0]){
       printf("inside print\n" );
			printf("The number of blocks read are %d in %s ms\n", block_count, argv[2]);
			printf("The memory read in %s ms is %d bytes\n", argv[2], block_count*buffer_size);
			break;
		}
		block_count++;
	}
	close(fd);
	diff = clock() - start;
	msec = diff * 1000 / CLOCKS_PER_SEC;
  double time = (msec+ msec%1000)/1000.0;
  double mb= (block_count*buffer_size)/1048576.0;
	printf("Speed in Megabytes per second is %f MiB/s \n", mb/time);
	printf("XOR result is %08x\n", result);
	return 0;
}
