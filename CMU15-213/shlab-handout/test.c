#include<unistd.h>
#include<stdio.h>

int main()
{
	char *argv[] = {"ls",NULL};
	char *envp[] = {"PATH=/bin",NULL};
	execve("/bin/ls",argv,envp);
	printf("hello\n");
	return 0;
}
