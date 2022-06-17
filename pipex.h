#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"
# include <unistd.h>
typedef struct s_pipex
{
	char	**av;
	char	**envp;
	char	*fpath;
	int		in_fd;
	int		out_fd;
	int		fd[2];
	int		pid1;
	int		pid2;
	char	**pcmd1;
	char	**pcmd2;
	char	**cmd1;
	char	**cmd2;
}				t_pipex;

t_pipex	*initilize(t_pipex *p, char **av, char **envp);
void	ft_error(char *str, char *error, int status, t_pipex *p);
t_pipex *pipex(t_pipex *p);
void	ft_quit(int status, t_pipex *p);

#endif