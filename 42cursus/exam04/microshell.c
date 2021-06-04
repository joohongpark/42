#include <unistd.h>
#include <string.h>
#include <stdlib.h>

typedef struct s_cmdlist {
	char		**argv;
	int			i;
	int			o;
	struct s_cmdlist *next;
}				t_cmdlist;

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

void ft_lstadd_back(t_cmdlist **lst, t_cmdlist *new) {
	t_cmdlist	*tmp;

	if (lst != NULL && *lst != NULL)
	{
		tmp = *lst;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	else if (*lst == NULL)
		*lst = new;
}

pid_t			ft_exec(char *exec, int i, int o, char **argv, char **envp)
{
	pid_t		rtn;
	int			io[2];

	rtn = fork();
	if (rtn < 0)
		ft_exit();
	if (rtn == 0)
	{
		if (i != STDIN_FILENO)
			io[0] = dup2(i, STDIN_FILENO);
		if (o != STDOUT_FILENO)
			io[1] = dup2(o, STDOUT_FILENO);
		if (execve(exec, argv, envp) != 0) {
			ft_print("error: cannot execute ", 2);
			ft_print(argv[0], 2);
			ft_print("\n", 2);
			exit(0);
		}
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

int run_cmd(t_cmdlist* cmd, char **envp) {
	int rtn = 0;
	int status;
	pid_t pid;

	if (strcmp(cmd->argv[0], "cd") == 0) {
		if (cmd->argv[1] == NULL || cmd->argv[2] != NULL)
			ft_print("error: cd: bad arguments", 2);
		else if (chdir(cmd->argv[1]) != 0) {
			ft_print("error: cd: cannot change directory to ", 2);
			ft_print(cmd->argv[1], 2);
			ft_print("\n", 2);
		}
	} else {
		pid = ft_exec(cmd->argv[0], cmd->i, cmd->o, cmd->argv, envp);
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		rtn = WEXITSTATUS(status);
	}
	return (rtn);
}

int run_list(t_cmdlist* cmdlist, char **envp) {
	int rtn = 0;
	(void) envp;
	while (cmdlist != NULL) {
		rtn = run_cmd(cmdlist, envp);
		cmdlist = cmdlist->next;
	}
	return (rtn);
}

void set_pipe(t_cmdlist* cmdlist) {
	int pair[2];

	while (cmdlist != NULL) {
		if (cmdlist->o == 1) {
			if (pipe(pair) != 0)
				ft_exit();
			cmdlist->o = pair[1];
			if (cmdlist->next != NULL)
				cmdlist->next->i = pair[0];
		} else {
			cmdlist->o = 1;
		}
		cmdlist = cmdlist->next;
	}
}

void free_list(t_cmdlist* cmdlist) {
	t_cmdlist* pointer;

	while (cmdlist != NULL) {
		pointer = cmdlist->next;
		free(cmdlist->argv);
		free(cmdlist);
		cmdlist = pointer;
	}
}

t_cmdlist *get_cmd(char **argv, int len, int is_pipe) {
	t_cmdlist *rtn = malloc(sizeof(t_cmdlist));
	char **strs = malloc(sizeof(char *) * (len + 1));

	if (rtn == NULL || strs == NULL)
		ft_exit();
	for (int i = 0; i < len; i++)
		strs[i] = argv[i];
	strs[len] = NULL;
	rtn->argv = strs;
	rtn->i = 0;
	rtn->o = is_pipe;
	rtn->next = NULL;
	return (rtn);
}

int main(int argc, char **argv, char **envp) {
	int rtn = 0;
	int start = 1;
	t_cmdlist *cmdlist = NULL;

	for (int i = start; i < argc; i++) {
		if (strcmp(argv[i], ";") == 0 || strcmp(argv[i], "|") == 0) {
			if ((i - start) != 0) {
				ft_lstadd_back(&cmdlist, get_cmd(&argv[start], (i - start), strcmp(argv[i], "|") == 0));
			}
			start = i + 1;
		} else if ((i + 1) == argc) {
			ft_lstadd_back(&cmdlist, get_cmd(&argv[start], (i - start + 1), 0));
		}
	}
	set_pipe(cmdlist);
	rtn = run_list(cmdlist, envp);
	free_list(cmdlist);
	return (rtn);
}