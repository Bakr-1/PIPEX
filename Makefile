# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalseri <aalseri@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/24 21:10:12 by aalseri           #+#    #+#              #
#    Updated: 2022/06/18 23:25:20 by aalseri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS = main.c pipex_utils1.c pipex_utils2.c error_handle.c
OBJS	= ${SRCS:.c=.o}
INCLUDES = pipex.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME} : ${OBJS}
	@echo "${CY}\nPreparing Libft!"
	@$(MAKE) --no-print-directory -C ./libft
	@echo "${GR}\nLibft is READY!"
	@${CC} ${CFLAGS} ${OBJS} ./libft/libft.a -o ${NAME}
	@echo "${YE}\nUseage './pipex (in_file) command command (out_file)'"

clean:
	@echo "${RE}Cleaning!"
	@rm -rf ${OBJS}
	@${MAKE} clean --no-print-directory -C libft

fclean: clean
	@rm -rf ${NAME}
	@${MAKE} fclean --no-print-directory -C libft

re: fclean all
	@${MAKE} re --no-print-directory -C ./libft

norme:
	norminette -R CheckForbiddenSourceHeader ${wildcard *.c} ${wildcard *.h} \
							${wildcard libft/*.c} ${wildcard libft/*.h} \
							${wildcard libft/gnl/*.c} ${wildcard libft/gnl/*.h} \
							${wildcard libft/ft_printf/*.c} ${wildcard libft/ft_printf/*.h}

GR	= \033[32;1m
RE	= \033[31;1m
YE	= \033[33;1m
CY	= \033[36;1m
RC	= \033[0m