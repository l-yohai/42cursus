# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/14 19:39:47 by yohlee            #+#    #+#              #
#    Updated: 2020/07/14 19:42:02 by yohlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCDIR = ./srcs/
SRCNAMES = $(shell ls $(SRCDIR) | grep -E ".+\.c")
SRCS = $(addprefix $(SRCDIR), $(SRCNAMES))
INCS = ./includes/
BUILDDIR = ./build/
BUILDOBJS = $(addprefix $(BUILDDIR), $(SRCNAMES:.c=.o))

LIBDIR = ./libft/
LIBFT = ./libft/libft.a
