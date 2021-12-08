#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>
int main(int argc, char* argv[]){
	clock_t start = clock(),diff, bin;
	int msec,msec2, block_count = 1;
	const int buffer_size = atoi(argv[2]);
	unsigned int result = 0;
	int fd = open(argv[1], 0), n;
	char buffer[buffer_size];
	int fullFileRead = 1;
	while((n = read(fd, buffer, sizeof(buffer))) > 0){
		bin = clock() - start;
		msec2 = bin * 1000 / CLOCKS_PER_SEC;
		if (msec2 > 5000) {
			printf("The number of blocks read are %d in 5 seconds\n",block_count);
			printf("The memory read in 5 seconds is %d bytes\n",block_count*buffer_size);
			fullFileRead = 0;
			break;
		}
		block_count++;
	}
	close(fd);
	if (fullFileRead == 1) {
		diff = clock() - start;
		msec = diff * 1000 / CLOCKS_PER_SEC;
		printf("The entire file has been read in %d seconds and %d milliseconds", msec/1000, msec%1000);
	}
	return 0;
}
