#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void ft_print(char *str, int fd) {
	int i = 0;

	while (str[i] != '\0')
		i++;
	write(fd, str, i);
}

void ft_exit(void) {
	ft_print("error: fatal\n", 2);
	exit(1);
}

int ft_exec(char **argv, int i, int o, char **envp)
{
	int			rtn = 0;
	pid_t		pid;
	int			io[2] = {0, 0};
	int			status;

	pid = fork();
	if (pid < 0)
		ft_exit();
	if (pid == 0) {
		if (i != 0)
			io[0] = dup2(i, 0);
		if (o != 1)
			io[1] = dup2(o, 1);
		if (io[0] < 0 || io[1] < 0)
			ft_exit();
		if (execve(argv[0], argv, envp) == -1) {
			ft_print("error: cannot execute ", 2);
			ft_print(argv[0], 2);
			ft_print("\n", 2);
			exit(1);
		}
	} else {
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			rtn = WEXITSTATUS(status);
	}
	return (rtn);
}

int run_cd(char **argv) {
	int rtn = 0;

	if (argv[1] == NULL || argv[2] != NULL) {
		ft_print("error: cd: bad arguments\n", 2);
		rtn = 1;
	} else if (chdir(argv[1]) != 0) {
		ft_print("error: cd: cannot change directory to ", 2);
		ft_print(argv[1], 2);
		ft_print("\n", 2);
		rtn = 1;
	}
	return (rtn);
}

void get_io(int *i, int *o, int final) {
	static int fd_in = 0;
	int pair[2];

	if (final == 1) {
		*i = fd_in;
		*o = 1;
		fd_in = 0;
	} else {
		if (pipe(pair) == -1)
			ft_exit();
		*i = fd_in;
		*o = pair[1];
		fd_in = pair[0];
	}
}

int run_cmd(char **argv, int len, int final, char **envp) {
	char **strs = malloc(sizeof(char *) * (len + 1));
	int rtn;
	int i;
	int o;

	if (strs == NULL)
		ft_exit();
	for (int i = 0; i < len; i++)
		strs[i] = argv[i];
	strs[len] = NULL;
	get_io(&i, &o, final);
	if (strcmp(strs[0], "cd") == 0)
		rtn = run_cd(strs);
	else
		rtn = ft_exec(strs, i, o, envp);
	if (i != 0)
		close(i);
	if (o != 1)
		close(o);
	free(strs);
	return (rtn);
}

int main(int argc, char **argv, char **envp) {
	int rtn = 0;
	int start = 1;

	for (int i = start; i < argc; i++) {
		if (strcmp(argv[i], ";") == 0 || strcmp(argv[i], "|") == 0) {
			if ((i - start) != 0) {
				rtn = run_cmd(&argv[start], (i - start), strcmp(argv[i], ";") == 0, envp);
			}
			start = i + 1;
		} else if ((i + 1) == argc) {
			rtn = run_cmd(&argv[start], (i - start + 1), 1, envp);
		}
	}
	return (rtn);
}