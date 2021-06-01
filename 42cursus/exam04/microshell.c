#include <unistd.h>
#include <string.h>
#include <stdio.h>

pid_t			ft_exec(char *exec, int i, int o, char **argv, char **envp)
{
	pid_t		rtn;
	int			io[2];

	rtn = fork();
	if (rtn == 0)
	{
		if (i != STDIN_FILENO)
			io[0] = dup2(i, STDIN_FILENO);
		if (o != STDOUT_FILENO)
			io[1] = dup2(o, STDOUT_FILENO);
		execve(exec, argv, envp);
	}
	else
	{
		if (i != STDIN_FILENO)
			close(i);
		if (o != STDOUT_FILENO)
			close(o);
	}
	return (rtn);
}

int main(int argc, char **argv, char **envp) {
	for (int i = 0; i < argc; i++)
	{
		if (strcmp(argv[i], ";") == 0)
			printf("found\n");
		printf("[%s]\n", argv[i]);
	}
	(void) envp;
	// ft_exec("/bin/ls", 0, 1, argv, envp);
	return (0);
}