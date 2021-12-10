#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>
#include<string.h>
#pragma GCC diagnostic ignored "-Wall"


int returnMaxFileSize(char* fileName, int bufferSize);

int main(int argc, char* argv[]) {
		printf("The maximum blocks read are %d\n", returnMaxFileSize(argv[1],atoi(argv[2])));
	return 0;
}

int returnMaxFileSize(char* fileName, int bufferSize){
	clock_t start = clock(),diff, bin;
	int msec,msec2, block_count = 1, n;
	int max_block = 0, count = 1;
	const int buffer_size = bufferSize;
	int fd = open(fileName, 0);
	char buffer[buffer_size];
	int fullFileRead = 1;
	while (1) {
		block_count = 1;
		fullFileRead = 1;
		fd = open(fileName, 0);
		start = clock();
		while((n = read(fd, buffer, sizeof(buffer))) > 0){
			bin = clock() - start;
			msec2 = bin * 1000 / CLOCKS_PER_SEC;
			if (block_count == count || msec2 > 5000) {
				if (max_block < block_count) {
					max_block = block_count;
				}
				fullFileRead = 0;
				break;
			}
			block_count++;
		}
		close(fd);
		if (block_count < count && fullFileRead == 0) {
			break;
		}
		count *= 2;
		if (fullFileRead == 1) {
			if(max_block< block_count){
				max_block= block_count;
			}
			diff = clock() - start;
			msec = diff * 1000 / CLOCKS_PER_SEC;
			printf("The entire file has been read in %d seconds and %d milliseconds\n", msec/1000, msec%1000);
			break;
		}
	}
	if(fullFileRead!=1){
	printf("The number of blocks read are %d in 5 seconds. \n",max_block);
	printf("The file size read in 5 seconds is %ld bytes\n",max_block*buffer_size);
}
	return max_block;
}
