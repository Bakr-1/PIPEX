/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalseri <aalseri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 21:44:26 by aalseri           #+#    #+#             */
/*   Updated: 2022/07/16 14:55:57 by aalseri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

size_t	ft_putpointer(unsigned long long p)
{
	size_t	len;

	len = 2;
	write(1, "0x", 2);
	if (p == 0)
	{
		write(1, "0", 1);
		return (3);
	}
	len += ft_puthexa(p, 'x');
	return (len);
}
