/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalseri <aalseri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 21:41:30 by aalseri           #+#    #+#             */
/*   Updated: 2022/06/23 16:57:45 by aalseri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../mem/libft.h"

int		ft_printf(const char *str, ...);
size_t	ft_crazy(const char *str, va_list ptr);
size_t	ft_puthexa(unsigned long long n, char c);
size_t	ft_putchar(int c);
size_t	ft_putnbr_un(unsigned int nb);
size_t	ft_putpointer(unsigned long long p);
size_t	ft_putstr(char *str);
size_t	ft_putnbr(int nb);

#endif
