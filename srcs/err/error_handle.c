/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalseri <aalseri@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 13:06:21 by aalseri           #+#    #+#             */
/*   Updated: 2022/08/08 11:43:20 by aalseri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_struct1(t_pipex *p)
{
	if (p->cmd1)
	{
		ft_undo_alloc(p->cmd1);
		free(p->cmd1);
		p->cmd1 = NULL;
	}
	if (p->cmd2)
	{
		ft_undo_alloc(p->cmd2);
		free(p->cmd2);
		p->cmd2 = NULL;
	}
	if (p->pcmd1)
	{
		ft_undo_alloc(p->pcmd1);
		free(p->pcmd1);
		p->pcmd1 = NULL;
	}
	if (p->pcmd2)
	{
		ft_undo_alloc(p->pcmd2);
		free(p->pcmd2);
		p->pcmd2 = NULL;
	}
}

void	ft_free_struct2(t_pipex *p)
{
	if (p->in_fd != -1)
		close(p->in_fd);
	if (p->out_fd != -1)
		close(p->out_fd);
	if (p->fd[0] != -1)
		close(p->fd[0]);
	if (p->fd[1] != -1)
		close(p->fd[1]);
}

void	close_error(t_pipex *p)
{
	if (p->in_fd != -1)
		close(p->in_fd);
	if (p->out_fd != -1)
		close(p->out_fd);
	if (p->fd[0] != -1)
		close(p->fd[0]);
	if (p->fd[1] != -1)
		close(p->fd[1]);
}

void	ft_error(char *str, char *error, int status, t_pipex *p)
{
	ft_putstr(str);
	ft_putchar('\t');
	ft_putendl_fd(error, status);
	ft_free_struct1(p);
	ft_free_struct2(p);
	close_error(p);
	free(p);
	exit(status);
}

void	ft_quit(int status, t_pipex *p)
{
	ft_free_struct1(p);
	ft_free_struct2(p);
	close_error(p);
	free(p);
	exit(status);
}
