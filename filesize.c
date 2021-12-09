#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int returnMaxFileSize(char* fileName, int bufferSize){
	clock_t start = clock(),diff, bin;
	int msec,msec2, block_count = 1, n;
	int max_block = 0, count = 1;
	const int buffer_size = bufferSize;
	int fd = open(fileName, 0);
	char buffer[buffer_size];
	int fullFileRead = 1;
	while (1) {
		start = clock();
		block_count = 1;
		fullFileRead = 1;
		fd = open(fileName, 0);
		while((n = read(fd, buffer, sizeof(buffer))) > 0){
			bin = clock() - start;
			msec2 = bin * 1000 / CLOCKS_PER_SEC;
			if (msec2 > 50 || block_count == count) {
				if (max_block < block_count) {
					max_block = block_count;
				}
				fullFileRead = 0;
				break;
			}
			block_count++;
		}
		close(fd);
		if (block_count < count)
			break;
		count *= 2;
		if (fullFileRead == 1) {
			diff = clock() - start;
			msec = diff * 1000 / CLOCKS_PER_SEC;
			printf("The entire file has been read in %d seconds and %d milliseconds", msec/1000, msec%1000);
			break;
		}
	}
	printf("The number of blocks read are %d in 5 seconds\n",max_block);
	printf("The memory read in 5 seconds is %d bytes\n",max_block*buffer_size);
	return max_block;
}
