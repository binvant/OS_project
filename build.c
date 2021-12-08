#include <stdio.h>
#include <stdlib.h>

int main(){
	system("gcc project.c -o proj");
  system("gcc fast.c -o fast");
	system("gcc timerun.c -o timerun");
	system("gcc filesize.c -o filesize");
	system("gcc write.c -o write");
	return 0;
}
