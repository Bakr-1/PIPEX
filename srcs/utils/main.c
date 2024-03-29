/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalseri <aalseri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 18:18:04 by aalseri           #+#    #+#             */
/*   Updated: 2022/08/09 11:29:14 by aalseri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	main(int ac, char **ag, char **envp)
{
	t_pipex	*p;

	if (ac != 5)
	{
		ft_putendl_fd("number of arguments must be 5", 2);
		exit(EXIT_FAILURE);
	}
	if (!ft_strlen(ag[2]) || !ft_strlen(ag[3]))
	{
		ft_putendl_fd("no command given", 2);
		exit(EXIT_FAILURE);
	}
	p = ft_calloc(1, sizeof(t_pipex));
	if (!p)
		ft_error("malloc error", strerror(errno), EXIT_FAILURE, p);
	p = initilize(p, ag, envp);
	p = pipex(p);
	ft_quit(EXIT_SUCCESS, p);
	return (0);
}
