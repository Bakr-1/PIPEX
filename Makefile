# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalseri <aalseri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/24 21:10:12 by aalseri           #+#    #+#              #
#    Updated: 2022/06/11 15:27:14 by aalseri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS = main.c pipex_utils_extra.c

INCLUDES = pipex.h

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME} :
	@${MAKE} -C libft
	$(CC) -g -o pipex ${SRCS} ./libft/libft.a
	@${MAKE} clean -C libft

onlypipe:
	$(CC) -g -o pipex ${SRCS} ./libft/libft.a

clean:
	rm -rf ${OBJS}
	@${MAKE} clean -C libft

fclean: clean
	rm -rf ${NAME}
	@${MAKE} fclean -C libft


re: fclean all
	${MAKE} re -C ./libft

cltr: fclean
	rm -rf ${NAME}

.PHONY: all clean fclean re
