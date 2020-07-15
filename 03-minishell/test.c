#include <stdio.h>
#include "libft/libft.h"

int		main(int	ac, char *av[])
{
	char	**strs;

	strs = ft_split(av[1], ' ');
	printf("%s\n", strs[0]);
}
