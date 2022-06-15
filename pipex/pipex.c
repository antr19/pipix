#include <stdio.h>
#include <unistd.h>

void child()
{
	printf("child\n");
}

void fparent()
{
	printf("parent\n");
}

void pipex(int f1, int f2)
{
	int end[2];
	int parent;

	parent = fork();
	if (parent < 0)
		return ;
	else if (!parent)
		child();
	else
		fparent();
	

	
}

int main(int argc, char **argv, char **env)
{
	char *args[2];
    args[0] = "/wc"; 
    args[1] = NULL;
    execve(args[0], args, NULL);
	pipex(1, 2);
	return(0);
}
