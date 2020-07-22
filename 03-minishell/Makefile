# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/08 22:07:17 by jujeong           #+#    #+#              #
#    Updated: 2020/07/21 17:19:04 by yohlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = minishell

FLAGS = -Wall -Wextra -Werror

LIBFT = libft

DIR_S = srcs

DIR_O = temporary

HEADER = includes

SOURCES =	main.c utils.c get_next_line.c cd.c convert.c\
			echo.c echo_print.c echo_utils.c env.c exec.c\
			exit.c export.c export_utils.c set.c path.c pipe.c\
			prompt.c pwd.c redirection.c unset.c var.c

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	cp libft/libft.a .
	$(CC) $(FLAGS) -I $(HEADER) -o $(NAME) $(OBJS) libft.a

$(DIR_O)/%.o: $(DIR_S)/%.c
	mkdir -p temporary
	$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

clean:
	rm -f $(OBJS)
	rm -rf $(DIR_O)
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME) libft.a
	make fclean -C $(LIBFT)

re: fclean all
