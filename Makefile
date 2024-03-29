# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalseri <aalseri@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/24 21:10:12 by aalseri           #+#    #+#              #
#    Updated: 2022/09/12 20:09:06 by aalseri          ###   ########           #
#                                                                              #
# **************************************************************************** #

NAME = pipex

DIR_SRCS	= srcs
DIR_OBJS	= objs
SUBDIRS		= err utils

SRCS_DIRS	= $(foreach dir, $(SUBDIRS), $(addprefix $(DIR_SRCS)/, $(dir)))
OBJS_DIRS	= $(foreach dir, $(SUBDIRS), $(addprefix $(DIR_OBJS)/, $(dir)))
SRCS		= $(foreach dir, $(SRCS_DIRS), $(wildcard $(dir)/*.c))
OBJS		= $(subst $(DIR_SRCS), $(DIR_OBJS), $(SRCS:.c=.o))

INCLUDES = -I ./includes
CC = gcc
CFLAGS = -Wall -Wextra -Werror

$(DIR_OBJS)/%.o :	$(DIR_SRCS)/%.c
			@mkdir -p $(DIR_OBJS) $(OBJS_DIRS)
			@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: ${NAME}

${NAME} : ${OBJS}
	@${MAKE} --no-print-directory -C libft
	@${CC} ${CFLAGS} ${OBJS} ${INCLUDES} ./libft/libft.a -o ${NAME}
	@echo "${BIYellow}\nUseage \"./pipex (in_file) command command (out_file)\"${Color_Off}"

clean:
	@echo "${BIRed}Cleaning!${Color_Off}"
	@${MAKE} --no-print-directory -i clean -C libft
	@rm -r ${DIR_OBJS}

fclean: clean
	@rm -rf ${NAME}
	@${MAKE} fclean --no-print-directory -C libft

re: fclean all

norme:
	norminette -R CheckForbiddenSourceHeader ${wildcard *.c} ${wildcard *.h}


party:
					@printf "\033c"
					@echo "\n\033[35m♪┏(・o･)┛♪  \033[1;33m♪┗(・o･)┓♪  \033[36m♪┏(・o･)┛♪  \033[34m♪┗(・o･)┓♪"
					@sleep 1
					@printf "\033c"
					@echo "\n\033[35m♪┗(・o･)┓♪  \033[1;33m♪┏(・o･)┛♪  \033[36m♪┗(・o･)┓♪  \033[34m♪┏(・o･)┛♪"
					@sleep 1
					@printf "\033c"
					@echo "\n\033[35m♪┏(・o･)┛♪  \033[1;33m♪┗(・o･)┓♪  \033[36m♪┏(・o･)┛♪  \033[34m♪┗(・o･)┓♪"
					@sleep 1
					@printf "\033c"
					@echo "\n\033[35m♪┗(・o･)┓♪  \033[1;33m♪┏(・o･)┛♪  \033[36m♪┗(・o･)┓♪  \033[34m♪┏(・o･)┛♪"
					${MAKE} party

# Reset
Color_Off=\033[0m       # Text Reset

# Regular Colors
Black=\033[0;30m        # Black
Red=\033[0;31m         # Red
Green=\033[0;32m        # Green
Yellow=\033[0;33m       # Yellow
Blue=\033[0;34m         # Blue
Purple=\033[0;35m       # Purple
Cyan=\033[0;36m         # Cyan
White=\033[0;37m        # White

# Bold
BBlack=\033[1;30m       # Black
BRed=\033[1;31m         # Red
BGreen=\033[1;32m       # Green
BYellow=\033[1;33m      # Yellow
BBlue=\033[1;34m        # Blue
BPurple=\033[1;35m      # Purple
BCyan=\033[1;36m        # Cyan
BWhite=\033[1;37m       # White

# Background
On_Black=\033[40m       # Black
On_Red=\033[41m         # Red
On_Green=\033[42m      # Green
On_Yellow=\033[43m      # Yellow
On_Blue=\033[44m        # Blue
On_Purple=\033[45m      # Purple
On_Cyan=\033[46m        # Cyan
On_White=\033[47m       # White

# High Intensty
IBlack=\033[0;90m       # Black
IRed=\033[0;91m         # Red
IGreen=\033[0;92m       # Green
IYellow=\033[0;93m      # Yellow
IBlue=\033[0;94m        # Blue
IPurple=\033[0;95m      # Purple
ICyan=\033[0;96m        # Cyan
IWhite=\033[0;97m       # White

# Bold High Intensty
BIBlack=\033[1;90m      # Black
BIRed=\033[1;91m        # Red
BIGreen=\033[1;92m      # Green
BIYellow=\033[1;93m     # Yellow
BIBlue=\033[1;94m       # Blue
BIPurple=\033[1;95m     # Purple
BICyan=\033[1;96m       # Cyan
BIWhite=\033[1;97m      # White

# High Intensty backgrounds
On_IBlack=\033[0;100m   # Black
On_IRed=\033[0;101m     # Red
On_IGreen=\033[0;102m   # Green
On_IYellow=\033[0;103m  # Yellow
On_IBlue=\033[0;104m    # Blue
On_IPurple=\033[10;95m  # Purple
On_ICyan=\033[0;106m    # Cyan
On_IWhite=\033[0;107m   # White
