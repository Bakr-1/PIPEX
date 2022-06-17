/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalseri <aalseri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 18:18:04 by aalseri           #+#    #+#             */
/*   Updated: 2022/06/17 18:20:36 by aalseri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **ag, char **envp)
{
	t_pipex	*p;

	if (ac != 5)
	{
		ft_putendl_fd("number of arguments must be 5", 2);
		exit(EXIT_FAILURE);
	}
	p = initilize(p, ag, envp);
	p = pipex(p);
	ft_quit(EXIT_SUCCESS, p);
	return (0);
}
