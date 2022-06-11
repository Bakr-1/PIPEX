/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_extra.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalseri <aalseri@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 11:31:44 by aalseri           #+#    #+#             */
/*   Updated: 2022/06/11 14:17:16 by aalseri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_data(t_pipex *data)
{
	data->envp = NULL;
	data->ac = 0;
	data->av = NULL;
	data->in_fd = 0;
	data->out_fd = -1;
	data->fpath = NULL;
	data->cmd1 = NULL;
	data->cmd2 = NULL;
}

char	*find_path(t_pipex *p)
{
	int	i;

	i = 0;
	while (p->envp[i])
	{
		if (!ft_strncmp(p->envp[i], "PATH=", 5))
			break;
		i++;
	}
	return (p->envp[i]);
}

// static char	**ret_cmd(t_pipex *data, int i)
// {
// 	char	**path;
// 	char	**cmd;
// 	char	*tmp_cmd;
// 	char	*tmp;

// 	path = find_path(data->envp);
// 	cmd = ft_split(data->av[i], ' ');
// 	if (!cmd)
// 		ft_error(EXIT_FAILURE, data);
// 	tmp_cmd = ft_strjoin("/", *cmd);
// 	if (!tmp_cmd)
// 		ft_error(EXIT_FAILURE, data);
// 	tmp = *cmd;
// 	*cmd = find_check_cmd(path, tmp_cmd);
// 	if (!(*cmd))
// 		ft_error(EXIT_FAILURE, data);
// 	ft_free(&tmp);
// 	ft_free(&tmp_cmd);
// 	ft_undo_alloc(path);
// 	return (cmd);
// }

char *find_command(char *str)
{
	
}

t_pipex	*open_fd_cmd(t_pipex *data)
{
	data->in_fd = open(data->av[1], O_RDONLY);
	if (data->in_fd == -1)
		ft_error(EXIT_FAILURE, data);
	data->out_fd = open(data->av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (data->out_fd == -1)
		ft_error(EXIT_FAILURE, data);
	data->fpath = find_path(data);
	
	data->cmd1 = find_command(data->av[2]);
	data->cmd2 = find_command(data->av[3]);
	return (data);
}

t_pipex	*initilize(int ac, char **av, char **envp)
{
	t_pipex	data;

	init_data(&data);
	data.envp = envp;
	data.ac = ac;
	data.av = av;
	open_fd_cmd(&data);
	// data->nb_cmds = ac - 3 - data->heredoc;
	// data->pids = malloc(sizeof * data->pids * data->nb_cmds);
	// if (!data->pids)
	// 	exit_error(msg("PID error", strerror(errno), "", 1), &data);
	// data->pipe = malloc(sizeof * data->pipe * 2 * (data->nb_cmds - 1));
	// if (!data->pipe)
	// 	exit_error(msg("Pipe error", "", "", 1), &data);
	// generate_pipes(&data);
}

void	ft_error(int status, t_pipex *data)
{
	exit(1);
}