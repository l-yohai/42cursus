/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 08:00:26 by yohlee            #+#    #+#             */
/*   Updated: 2020/07/12 16:57:36 by yohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int			ft_strlen(char const *str);
int			ft_strcmp(char const *s1, char const *s2);
char		*ft_strcpy(char *dst, char const *src);
ssize_t		ft_write(int fd, void const *buf, size_t nbyte);
ssize_t		ft_read(int fd, void *buf, size_t nbyte);
char		*ft_strdup(char const *s1);

void	test_strlen(char *s)
{
	printf("\n");
	printf("==========start==========\n");
	printf("strlen test\n");
	printf("string: %s\n", s);
	printf("ft_strlen: %d\n", ft_strlen(s));
	printf("===========end===========\n\n");
}

void	test_strcmp(char *s1, char *s2)
{
	printf("\n");
	printf("==========start==========\n");
	printf("strcmp test\n");
	printf("s1: %s\ns2: %s\n", s1, s2);
	printf("ft_strcmp: %d\n", ft_strcmp(s1, s2));
	printf("===========end===========\n\n");
}

void	test_strcpy(char *s1, char *s2)
{
	printf("\n");
	printf("==========start==========\n");
	printf("strcpy test\n");
	printf("string: %s\n", s2);
	printf("ft_strcpy: %s\n", ft_strcpy(s1, s2));
	printf("===========end===========\n\n");
}

void	test_strdup(char *s1)
{
	printf("\n");
	printf("==========start==========\n");
	printf("strdup test\n");
	printf("string: %s\n", s1);
	printf("ft_strdup: %s\n", ft_strdup(s1));
	printf("===========end===========\n\n");
}

void	test_read_write(int fd, void *buf, size_t nbyte)
{
	printf("\n");
	printf("==========start==========\n");
	printf("read & write test\n");
	while (ft_read(fd, buf, nbyte))
		ft_write(1, buf, nbyte);
	printf("\n");
	printf("===========end===========\n\n");
}

int		main(void)
{
	int		fd;
	char	buf;
	char	s[15] = "Hello World!";
	char	test[15];

	fd = open("test", O_RDONLY);
	test_strlen(s);
	test_strcpy(test, s);
	test_strcmp(s, "Hello world");
	test_strdup(s);
	test_read_write(fd, &buf, 1);
	close(fd);
	return (0);
}
