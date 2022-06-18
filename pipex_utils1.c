/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalseri <aalseri@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 11:31:44 by aalseri           #+#    #+#             */
/*   Updated: 2022/06/18 22:18:49 by aalseri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(t_pipex *p)
{
	int	i;

	i = 0;
	while (p->envp[i])
	{
		if (!ft_strncmp(p->envp[i], "PATH=", 5))
			break ;
		i++;
	}
	return (p->envp[i]);
}

char	*find_check_cmd(char *path, char *t_cmd)
{
	char	**str;
	int		i;
	char	*s;

	i = 0;
	path += 6;
	str = ft_split(path, ':');
	if (!str)
		return (NULL);
	while (str[i] != NULL)
	{
		s = ft_strjoin(str[i], t_cmd);
		if (!s)
			return (NULL);
		if (access(s, R_OK) == 0)
		{
			ft_undo_alloc(str);
			free(str);
			return (s);
		}
		free(s);
		s = NULL;
		i++;
	}
	return (NULL);
}

char	**ret_cmd(t_pipex *p, int i)
{
	char	*path;
	char	**cmd;
	char	*t_cmd;
	char	*s;

	path = find_path(p);
	if (i == 2)
		p->pcmd1 = ft_split(p->av[i], ' ');
	if (i == 3)
		p->pcmd2 = ft_split(p->av[i], ' ');
	cmd = ft_split(p->av[i], ' ');
	if (!cmd && !p->pcmd1 && !p->pcmd2)
		ft_error("split", strerror(errno), EXIT_FAILURE, p);
	t_cmd = ft_strjoin("/", *cmd);
	if (!t_cmd)
		ft_error("strjoin", strerror(errno), EXIT_FAILURE, p);
	free(cmd[0]);
	cmd[0] = find_check_cmd(path, t_cmd);
	if (!(*cmd))
		ft_error("cmd check", strerror(errno), EXIT_FAILURE, p);
	free(t_cmd);
	return (cmd);
}

t_pipex	*open_fd_cmd(t_pipex *p)
{
	p->in_fd = open(p->av[1], O_RDONLY);
	if (p->in_fd == -1)
		ft_error("fd error", strerror(errno), EXIT_FAILURE, p);
	p->out_fd = open(p->av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (p->out_fd == -1)
		ft_error("fd error", strerror(errno), EXIT_FAILURE, p);
	p->fpath = find_path(p);
	p->cmd1 = ret_cmd(p, 2);
	p->cmd2 = ret_cmd(p, 3);
	return (p);
}

t_pipex	*initilize(t_pipex *p, char **av, char **envp)
{
	p = ft_calloc(1, sizeof(t_pipex));
	if (!p)
		ft_error("malloc error", strerror(errno), EXIT_FAILURE, p);
	p->envp = envp;
	p->av = av;
	p = open_fd_cmd(p);
	return (p);
}
