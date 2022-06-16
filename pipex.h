#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"
typedef struct s_pipex
{
	int		ac;
	char	**av;
	char	**envp;
	char	*fpath;
	int		in_fd;
	int		out_fd;
	char	**cmd1;
	char	**cmd2;
}				t_pipex;

t_pipex	*initilize(int ac, char **av, char **envp);
void	ft_error(int status, t_pipex *data);

#endif