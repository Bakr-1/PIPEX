/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalseri <aalseri@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 22:20:50 by aalseri           #+#    #+#             */
/*   Updated: 2022/06/19 01:18:06 by aalseri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
t_pipex	*pipex(t_pipex *p);
void	ft_quit(int status, t_pipex *p);
char	*find_path(t_pipex *p);
char	*find_check_cmd(char *path, char *t_cmd);

#endif