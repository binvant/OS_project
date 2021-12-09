#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "filesize.c"

int main(int argc, char* argv[]) {
	char cmd[100] = "proj";
	printf("The maximum block size returned is %d\n", returnMaxFileSize(argv[1], atoi(argv[2])));
	/*if (argc >= 2) {
		strcat(cmd, " ");
		strcat(cmd, argv[1]);
	}
	strcat(cmd, " ");
	strcat(cmd, argv[2]);
	strcat(cmd, " ");
	strcat(cmd, argv[3]);
	strcat(cmd, " ");
	strcat(cmd, argv[4]);
	system(cmd);*/
	return 0;
}
