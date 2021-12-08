#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main(int argc, char* argv[]) {
	if (strcmp(argv[2], "-r")== 0){
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

	}
	else
	{
		char cmd1[100] = "./write";
		strcat(cmd1, " ");
		strcat(cmd1, argv[1]);
		strcat(cmd1, " ");
		strcat(cmd1, argv[2]);
		strcat(cmd1, " ");
		strcat(cmd1, argv[3]);
	  system(cmd1);
	}

	return 0;
}
