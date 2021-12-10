#include <stdio.h>
#include <stdlib.h>
#pragma GCC diagnostic ignored "-Wall"

int main(){
	system("gcc -O3 project.c -o proj");
  system("gcc -O3 fast.c -o fast");
	system("gcc -O3 run.c -o run");
	system("gcc -O3 run2.c -o run2");
	system("gcc -O3 timerun.c -o timerun");
	//system("gcc filesize.c -o filesize");
	system("gcc -O3 write.c -o write");
	return 0;
}
