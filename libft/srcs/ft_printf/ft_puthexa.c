/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalseri <aalseri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 21:44:06 by aalseri           #+#    #+#             */
/*   Updated: 2022/07/16 14:56:08 by aalseri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

size_t	ft_puthexa(unsigned long long n, char c)
{
	char	*base;
	size_t	len;

	len = 0;
	base = "0123456789ABCDEF";
	if (c == 'x')
		base = "0123456789abcdef";
	if (n > 15)
		len += ft_puthexa(n / 16, c);
	len += ft_putchar(base[n % 16]);
	return (len);
}
