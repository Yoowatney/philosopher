# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoyoo <yoyoo@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/01 14:50:59 by yoyoo             #+#    #+#              #
#    Updated: 2021/12/01 19:55:34 by yoyoo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -g #-fsanitize=address 
SRCS_DIR		= ./src
SRCS			= $(addprefix $(SRCS_DIR)/, main.c parsing.c utils.c system_call.c thread.c utils2.c)

OBJS_DIR		= ./obj
OBJS			= $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))
NAME			= philo

all				: $(OBJS_DIR) $(NAME)

$(OBJS_DIR)		:
	@mkdir $(OBJS_DIR)

vpath %.c $(SRCS_DIR)

$(OBJS_DIR)/%.o	: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME)			: $(OBJS) ./philo.h
	@$(CC) $(CFLAGS) $(OBJS) -o $@
	@printf "   \033[0;32m[philo build success🔳]\n\e[0m"
	
re				: fclean all

clean			:
	@rm -f $(OBJS)
	@printf "   \033[0;32m[execute clean🥡]\n\e[0m"

fclean			: clean
	@rm -f $(NAME)
	@rm -rf $(OBJS_DIR)
	@printf "   \033[0;32m[execute fclean🚽]\n\e[0m"

