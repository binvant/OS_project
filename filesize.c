#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]){
	clock_t start = clock(),diff, bin;
	int msec,msec2, block_count = 1;
	const int buffer_size = atoi(argv[2]);
	unsigned int result = 0;
	int fd = open(argv[1], 0), n;
	char buffer[buffer_size];
	while((n = read(fd, buffer, sizeof(buffer))) > 0){
		bin = clock() - start;
		msec2 = bin * 1000 / CLOCKS_PER_SEC;
		if (msec2 > 10) {
			printf("The number of blocks read are %d in 10 ms\n",block_count);
			printf("The memory read in 100 ms is %d bytes\n",block_count*buffer_size);
			break;
		}
		block_count++;
	}
	close(fd);
	/*diff = clock() - start;
	msec = diff * 1000 / CLOCKS_PER_SEC;
	printf("The number of blocks are %d",block_count);
	printf("Time taken %d seconds %d milliseconds\n", msec/1000, msec%1000);
	printf("XOR result is %d", result);*/
	return 0;
}
