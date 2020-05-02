# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/18 23:31:37 by yohlee            #+#    #+#              #
#    Updated: 2020/05/02 21:22:33 by yohlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = ./libft/libft.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra
INCLUDES = -I./

SRCS = apply_options.c\
		ft_printf_c.c\
		ft_printf_di.c\
		ft_printf_p.c\
		ft_printf_s.c\
		ft_printf_ux.c\
		ft_printf.c\
		get_data.c\
		get_opt.c\

OBJS = $(SRCS:%.c=%.o)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft bonus
	cp $(LIBFT) $(NAME)
	ar rc $(NAME) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

all: $(NAME)

clean:
	$(MAKE) -C ./libft clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C ./libft fclean
	rm -f $(NAME)

bonus: all

re: fclean all

.PHONY: test bonus all clean fclean re

