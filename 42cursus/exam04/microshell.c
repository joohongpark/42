#include <unistd.h>
#include <string.h>
#include <stdlib.h>
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

void get_cmd(char **argv, int len, char **envp) {
	char **strs = malloc(sizeof(char *) * (len + 1));
	for (int i = 0; i < len; i++) {
		printf("[%s] ", argv[i]);
		strs[i] = argv[i];
	}
	strs[len] = NULL;
	ft_exec(strs[0], 0, 1, strs, envp);
	free(strs);
}

void get_cmds(char **argv, int len, char **envp) {
	int start = 0;
	for (int i = 0; i < len; i++)
	{
		if (strcmp(argv[i], "|") == 0) {
			if ((i - start) != 0)
				get_cmd(&argv[start], (i - start), envp);
			start = i + 1;
		}
	}
	printf("\n");
}

int main(int argc, char **argv, char **envp) {
	int start = 1;
	for (int i = start; i < argc; i++)
	{
		if (strcmp(argv[i], ";") == 0) {
			if ((i - start) != 0)
				get_cmd(&argv[start], (i - start), envp);
			start = i + 1;
		} else if ((i + 1) == argc) {
			get_cmd(&argv[start], (i - start + 1), envp);
		}
	}
	return (0);
}