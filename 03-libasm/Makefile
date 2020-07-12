NAME = libasm.a

SRCS = srcs/ft_strlen.s\
	srcs/ft_strcpy.s\
	srcs/ft_strcmp.s\
	srcs/ft_write.s\
	srcs/ft_read.s\
	srcs/ft_strdup.s

OBJS = $(SRCS:.s=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra

.s.o:
	nasm -f macho64 $<

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: $(NAME)
	$(CC) main.c -I. -L. -lasm $(CFLAGS)
	@./a.out
