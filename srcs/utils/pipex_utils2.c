/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalseri <aalseri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:57:33 by aalseri           #+#    #+#             */
/*   Updated: 2022/08/09 11:28:30 by aalseri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

t_pipex	*child_pipex(t_pipex *p)
{
	if (p->pid1)
	{
		dup2(p->in_fd, STDIN_FILENO);
		dup2(p->fd[1], STDOUT_FILENO);
		close(p->fd[0]);
		close(p->in_fd);
		execve(p->cmd1[0], p->pcmd1, p->envp);
	}
	else
	{
		p->pid2 = fork();
		if (p->pid2)
		{
			dup2(p->out_fd, STDOUT_FILENO);
			dup2(p->fd[0], STDIN_FILENO);
			close(p->fd[1]);
			close(p->out_fd);
			execve(p->cmd2[0], p->pcmd2, p->envp);
		}
	}
	wait(0);
	wait(0);
	return (p);
}

t_pipex	*pipex(t_pipex *p)
{
	if (pipe(p->fd) == -1)
		ft_error("pipe", strerror(errno), EXIT_FAILURE, p);
	p->pid1 = fork();
	if (p->pid1 == -1)
		ft_error("fork", strerror(errno), EXIT_FAILURE, p);
	child_pipex(p);
	return (p);
}
