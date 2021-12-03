#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main(int argc, char* argv[]) {
	char cmd[100] = "./proj";
	strcat(cmd, " ");
	strcat(cmd, argv[1]);
	strcat(cmd, " ");
	strcat(cmd, argv[2]);
	strcat(cmd, " ");
	strcat(cmd, argv[3]);
	strcat(cmd, " ");
	strcat(cmd, argv[4]);
	system(cmd);
	return 0;
}
