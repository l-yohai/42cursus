#include <stdio.h>
#include "ft_printf.h"

int	main()
{
	int	r1;
	int	r2;
	// c 경우의수
	// r1 =    printf("org: |%c|\n", 'a');
	// r2 = ft_printf("my : |%c|\n", 'a');
	// printf("origin: %d, my: %d\n\n", r1, r2);

	// r1 =    printf("org: |%-c|\n", 'a');
	// r2 = ft_printf("my : |%-c|\n", 'a');
	// printf("origin: %d, my: %d\n\n", r1, r2);

	// r1 =    printf("org: |%10c|\n", 'a');
	// r2 = ft_printf("my : |%10c|\n", 'a');
	// printf("origin: %d, my: %d\n\n", r1, r2);

	// r1 =    printf("org: |%-10c|\n", 'a');
	// r2 = ft_printf("my : |%-10c|\n", 'a');
	// printf("origin: %d, my: %d\n\n", r1, r2);

	// r1 =    printf("org: |%c|\n", '\0');
	// r2 = ft_printf("my : |%c|\n", '\0');
	// printf("origin: %d, my: %d\n\n", r1, r2);

	// r1 =    printf("org: |%-c|\n", '\0');
	// r2 = ft_printf("my : |%-c|\n", '\0');
	// printf("origin: %d, my: %d\n\n", r1, r2);

	// r1 =    printf("org: |%10c|\n", '\0');
	// r2 = ft_printf("my : |%10c|\n", '\0');
	// printf("origin: %d, my: %d\n\n", r1, r2);

	// r1 =    printf("org: |%-10c|\n", '\0');
	// r2 = ft_printf("my : |%-10c|\n", '\0');
	// printf("origin: %d, my: %d\n\n", r1, r2);

	// s 경우의수
	// r1 =    printf("org: |%s|\n", "HELLO");
	// r2 = ft_printf("my : |%s|\n", "HELLO");
	// printf("origin: %d, my: %d\n\n", r1, r2);

	// r1 =    printf("org: |%-s|\n", "HELLO");
	// r2 = ft_printf("my : |%-s|\n", "HELLO");
	// printf("origin: %d, my: %d\n\n", r1, r2);

	// r1 =    printf("org: |%10s|\n", "HELLO");
	// r2 = ft_printf("my : |%10s|\n", "HELLO");
	// printf("origin: %d, my: %d\n\n", r1, r2);

	// r1 =    printf("org: |%.10s|\n", "HELLO");
	// r2 = ft_printf("my : |%.10s|\n", "HELLO");
	// printf("origin: %d, my: %d\n\n", r1, r2);

	// r1 =    printf("org: |%-10s|\n", "HELLO");
	// r2 = ft_printf("my : |%-10s|\n", "HELLO");
	// printf("origin: %d, my: %d\n\n", r1, r2);

	// r1 =    printf("org: |%10.5s|\n", "HELLO");
	// r2 = ft_printf("my : |%10.5s|\n", "HELLO");
	// printf("origin: %d, my: %d\n\n", r1, r2);

	// r1 =    printf("org: |%5.10s|\n", "HELLO");
	// r2 = ft_printf("my : |%5.10s|\n", "HELLO");
	// printf("origin: %d, my: %d\n\n", r1, r2);

	// r1 =    printf("org: |%-10.5s|\n", "HELLO");
	// r2 = ft_printf("my : |%-10.5s|\n", "HELLO");
	// printf("origin: %d, my: %d\n\n", r1, r2);

	// r1 =    printf("org: |%-5.10s|\n", "HELLO");
	// r2 = ft_printf("my : |%-5.10s|\n", "HELLO");
	// printf("origin: %d, my: %d\n\n", r1, r2);


	// r1 =    printf("org: |%s|\n", "HELLO");
	// r2 = ft_printf("my : |%s|\n", "HELLO");
	// printf("origin: %d, my: %d\n\n", r1, r2);

	// r1 =    printf("org: |%-s|\n", "HELLO");
	// r2 = ft_printf("my : |%-s|\n", "HELLO");
	// printf("origin: %d, my: %d\n\n", r1, r2);

	// r1 =    printf("org: |%3s|\n", "HELLO");
	// r2 = ft_printf("my : |%3s|\n", "HELLO");
	// printf("origin: %d, my: %d\n\n", r1, r2);

	// r1 =    printf("org: |%.3s|\n", "HELLO");
	// r2 = ft_printf("my : |%.3s|\n", "HELLO");
	// printf("origin: %d, my: %d\n\n", r1, r2);

	// r1 =    printf("org: |%-3s|\n", "HELLO");
	// r2 = ft_printf("my : |%-3s|\n", "HELLO");
	// printf("origin: %d, my: %d\n\n", r1, r2);

	// r1 =    printf("org: |%3.2s|\n", "HELLO");
	// r2 = ft_printf("my : |%3.2s|\n", "HELLO");
	// printf("origin: %d, my: %d\n\n", r1, r2);

	// r1 =    printf("org: |%2.3s|\n", "HELLO");
	// r2 = ft_printf("my : |%2.3s|\n", "HELLO");
	// printf("origin: %d, my: %d\n\n", r1, r2);

	// r1 =    printf("org: |%-3.2s|\n", "HELLO");
	// r2 = ft_printf("my : |%-3.2s|\n", "HELLO");
	// printf("origin: %d, my: %d\n\n", r1, r2);

	// r1 =    printf("org: |%-2.3s|\n", "HELLO");
	// r2 = ft_printf("my : |%-2.3s|\n", "HELLO");
	// printf("origin: %d, my: %d\n\n", r1, r2);


	// r1 =    printf("org: |%s|\n", "");
	// r2 = ft_printf("my : |%s|\n", "");
	// printf("origin: %d, my: %d\n\n", r1, r2);

	// r1 =    printf("org: |%-s|\n", "");
	// r2 = ft_printf("my : |%-s|\n", "");
	// printf("origin: %d, my: %d\n\n", r1, r2);

	// r1 =    printf("org: |%10s|\n", "");
	// r2 = ft_printf("my : |%10s|\n", "");
	// printf("origin: %d, my: %d\n\n", r1, r2);

	// r1 =    printf("org: |%.10s|\n", "");
	// r2 = ft_printf("my : |%.10s|\n", "");
	// printf("origin: %d, my: %d\n\n", r1, r2);

	// r1 =    printf("org: |%-10s|\n", "");
	// r2 = ft_printf("my : |%-10s|\n", "");
	// printf("origin: %d, my: %d\n\n", r1, r2);

	// r1 =    printf("org: |%10.5s|\n", "");
	// r2 = ft_printf("my : |%10.5s|\n", "");
	// printf("origin: %d, my: %d\n\n", r1, r2);

	// r1 =    printf("org: |%5.10s|\n", "");
	// r2 = ft_printf("my : |%5.10s|\n", "");
	// printf("origin: %d, my: %d\n\n", r1, r2);

	// r1 =    printf("org: |%-10.5s|\n", "");
	// r2 = ft_printf("my : |%-10.5s|\n", "");
	// printf("origin: %d, my: %d\n\n", r1, r2);

	// r1 =    printf("org: |%-5.10s|\n", "");
	// r2 = ft_printf("my : |%-5.10s|\n", "");
	// printf("origin: %d, my: %d\n\n", r1, r2);


	// r1 =    printf("org: |%s|\n", "");
	// r2 = ft_printf("my : |%s|\n", "");
	// printf("origin: %d, my: %d\n\n", r1, r2);

	// r1 =    printf("org: |%-s|\n", "");
	// r2 = ft_printf("my : |%-s|\n", "");
	// printf("origin: %d, my: %d\n\n", r1, r2);

	// r1 =    printf("org: |%3s|\n", "");
	// r2 = ft_printf("my : |%3s|\n", "");
	// printf("origin: %d, my: %d\n\n", r1, r2);

	// r1 =    printf("org: |%.3s|\n", "");
	// r2 = ft_printf("my : |%.3s|\n", "");
	// printf("origin: %d, my: %d\n\n", r1, r2);

	// r1 =    printf("org: |%-3s|\n", "");
	// r2 = ft_printf("my : |%-3s|\n", "");
	// printf("origin: %d, my: %d\n\n", r1, r2);

	// r1 =    printf("org: |%3.2s|\n", "");
	// r2 = ft_printf("my : |%3.2s|\n", "");
	// printf("origin: %d, my: %d\n\n", r1, r2);

	// r1 =    printf("org: |%2.3s|\n", "");
	// r2 = ft_printf("my : |%2.3s|\n", "");
	// printf("origin: %d, my: %d\n\n", r1, r2);

	// r1 =    printf("org: |%-3.2s|\n", "");
	// r2 = ft_printf("my : |%-3.2s|\n", "");
	// printf("origin: %d, my: %d\n\n", r1, r2);

	// r1 =    printf("org: |%-2.3s|\n", "");
	// r2 = ft_printf("my : |%-2.3s|\n", "");
	// printf("origin: %d, my: %d\n\n", r1, r2);




	// r1 =    printf("org: |%s|\n", NULL);
	// r2 = ft_printf("my : |%s|\n", NULL);
	// printf("origin: %d, my: %d\n\n", r1, r2);

	// r1 =    printf("org: |%-s|\n", NULL);
	// r2 = ft_printf("my : |%-s|\n", NULL);
	// printf("origin: %d, my: %d\n\n", r1, r2);

	// r1 =    printf("org: |%10s|\n", NULL);
	// r2 = ft_printf("my : |%10s|\n", NULL);
	// printf("origin: %d, my: %d\n\n", r1, r2);

	// r1 =    printf("org: |%.10s|\n", NULL);
	// r2 = ft_printf("my : |%.10s|\n", NULL);
	// printf("origin: %d, my: %d\n\n", r1, r2);

	// r1 =    printf("org: |%-10s|\n", NULL);
	// r2 = ft_printf("my : |%-10s|\n", NULL);
	// printf("origin: %d, my: %d\n\n", r1, r2);

	// r1 =    printf("org: |%10.5s|\n", NULL);
	// r2 = ft_printf("my : |%10.5s|\n", NULL);
	// printf("origin: %d, my: %d\n\n", r1, r2);

	// r1 =    printf("org: |%5.10s|\n", NULL);
	// r2 = ft_printf("my : |%5.10s|\n", NULL);
	// printf("origin: %d, my: %d\n\n", r1, r2);

	// r1 =    printf("org: |%-10.5s|\n", NULL);
	// r2 = ft_printf("my : |%-10.5s|\n", NULL);
	// printf("origin: %d, my: %d\n\n", r1, r2);

	// r1 =    printf("org: |%-5.10s|\n", NULL);
	// r2 = ft_printf("my : |%-5.10s|\n", NULL);
	// printf("origin: %d, my: %d\n\n", r1, r2);


	// r1 =    printf("org: |%s|\n", NULL);
	// r2 = ft_printf("my : |%s|\n", NULL);
	// printf("origin: %d, my: %d\n\n", r1, r2);

	// r1 =    printf("org: |%-s|\n", NULL);
	// r2 = ft_printf("my : |%-s|\n", NULL);
	// printf("origin: %d, my: %d\n\n", r1, r2);

	// r1 =    printf("org: |%3s|\n", NULL);
	// r2 = ft_printf("my : |%3s|\n", NULL);
	// printf("origin: %d, my: %d\n\n", r1, r2);

	// r1 =    printf("org: |%.3s|\n", NULL);
	// r2 = ft_printf("my : |%.3s|\n", NULL);
	// printf("origin: %d, my: %d\n\n", r1, r2);

	// r1 =    printf("org: |%-3s|\n", NULL);
	// r2 = ft_printf("my : |%-3s|\n", NULL);
	// printf("origin: %d, my: %d\n\n", r1, r2);

	// r1 =    printf("org: |%3.2s|\n", NULL);
	// r2 = ft_printf("my : |%3.2s|\n", NULL);
	// printf("origin: %d, my: %d\n\n", r1, r2);

	// r1 =    printf("org: |%2.3s|\n", NULL);
	// r2 = ft_printf("my : |%2.3s|\n", NULL);
	// printf("origin: %d, my: %d\n\n", r1, r2);

	// r1 =    printf("org: |%-3.2s|\n", NULL);
	// r2 = ft_printf("my : |%-3.2s|\n", NULL);
	// printf("origin: %d, my: %d\n\n", r1, r2);

	// r1 =    printf("org: |%-2.3s|\n", NULL);
	// r2 = ft_printf("my : |%-2.3s|\n", NULL);
	// printf("origin: %d, my: %d\n\n", r1, r2);


	// d 경우의수
	// r1 =    printf("org: |%10d|\n", 123);
	// r2 = ft_printf("my : |%10d|\n", 123);
	// printf("origin: %d, my: %d\n\n", r1, r2);
	// r1 =    printf("org: |%.10d|\n", 123);
	// r2 = ft_printf("my : |%.10d|\n", 123);
	// printf("origin: %d, my: %d\n\n", r1, r2);
	// r1 =    printf("org: |%5.10d|\n", 123);
	// r2 = ft_printf("my : |%5.10d|\n", 123);
	// printf("origin: %d, my: %d\n\n", r1, r2);
	// r1 =    printf("org: |%10.5d|\n", 123);
	// r2 = ft_printf("my : |%10.5d|\n", 123);
	// printf("origin: %d, my: %d\n\n", r1, r2);
	// r1 =    printf("org: |%-d|\n", 123);
	// r2 = ft_printf("my : |%-d|\n", 123);
	// printf("origin: %d, my: %d\n\n", r1, r2);
	// r1 =    printf("org: |%0d|\n", 123);
	// r2 = ft_printf("my : |%0d|\n", 123);
	// printf("origin: %d, my: %d\n\n", r1, r2);
	// r1 =    printf("org: |%-5d|\n", 123);
	// r2 = ft_printf("my : |%-5d|\n", 123);
	// printf("origin: %d, my: %d\n\n", r1, r2);
	// r1 =    printf("org: |%-.5d|\n", 123);
	// r2 = ft_printf("my : |%-.5d|\n", 123);
	// printf("origin: %d, my: %d\n\n", r1, r2);
	// r1 =    printf("org: |%-5.10d|\n", 123);
	// r2 = ft_printf("my : |%-5.10d|\n", 123);
	// printf("origin: %d, my: %d\n\n", r1, r2);
	// r1 =    printf("org: |%-10.5d|\n", 123);
	// r2 = ft_printf("my : |%-10.5d|\n", 123);
	// printf("origin: %d, my: %d\n\n", r1, r2);
	// r1 =    printf("org: |%05d|\n", 123);
	// r2 = ft_printf("my : |%05d|\n", 123);
	// printf("origin: %d, my: %d\n\n", r1, r2);
	// r1 =    printf("org: |%0.5d|\n", 123);
	// r2 = ft_printf("my : |%0.5d|\n", 123);
	// printf("origin: %d, my: %d\n\n", r1, r2);
	// r1 =    printf("org: |%05.10d|\n", 123);
	// r2 = ft_printf("my : |%05.10d|\n", 123);
	// printf("origin: %d, my: %d\n\n", r1, r2);
	// r1 =    printf("org: |%010.5d|\n", 123);
	// r2 = ft_printf("my : |%010.5d|\n", 123);
	// printf("origin: %d, my: %d\n\n", r1, r2);


	// r1 =    printf("org: |%10d|\n", -123);
	// r2 = ft_printf("my : |%10d|\n", -123);
	// printf("origin: %d, my: %d\n\n", r1, r2);
	// r1 =    printf("org: |%.10d|\n", -123);
	// r2 = ft_printf("my : |%.10d|\n", -123);
	// printf("origin: %d, my: %d\n\n", r1, r2);
	// r1 =    printf("org: |%5.10d|\n", -123);
	// r2 = ft_printf("my : |%5.10d|\n", -123);
	// printf("origin: %d, my: %d\n\n", r1, r2);
	// r1 =    printf("org: |%10.5d|\n", -123);
	// r2 = ft_printf("my : |%10.5d|\n", -123);
	// printf("origin: %d, my: %d\n\n", r1, r2);
	// r1 =    printf("org: |%-d|\n", -123);
	// r2 = ft_printf("my : |%-d|\n", -123);
	// printf("origin: %d, my: %d\n\n", r1, r2);
	// r1 =    printf("org: |%0d|\n", -123);
	// r2 = ft_printf("my : |%0d|\n", -123);
	// printf("origin: %d, my: %d\n\n", r1, r2);
	// r1 =    printf("org: |%-5d|\n", -123);
	// r2 = ft_printf("my : |%-5d|\n", -123);
	// printf("origin: %d, my: %d\n\n", r1, r2);
	// r1 =    printf("org: |%-.5d|\n", -123);
	// r2 = ft_printf("my : |%-.5d|\n", -123);
	// printf("origin: %d, my: %d\n\n", r1, r2);
	// r1 =    printf("org: |%-5.10d|\n", -123);
	// r2 = ft_printf("my : |%-5.10d|\n", -123);
	// printf("origin: %d, my: %d\n\n", r1, r2);
	// r1 =    printf("org: |%-10.5d|\n", -123);
	// r2 = ft_printf("my : |%-10.5d|\n", -123);
	// printf("origin: %d, my: %d\n\n", r1, r2);
	// r1 =    printf("org: |%05d|\n", -123);
	// r2 = ft_printf("my : |%05d|\n", -123);
	// printf("origin: %d, my: %d\n\n", r1, r2);
	// r1 =    printf("org: |%0.5d|\n", -123);
	// r2 = ft_printf("my : |%0.5d|\n", -123);
	// printf("origin: %d, my: %d\n\n", r1, r2);
	// r1 =    printf("org: |%05.10d|\n", -123);
	// r2 = ft_printf("my : |%05.10d|\n", -123);
	// printf("origin: %d, my: %d\n\n", r1, r2);
	// r1 =    printf("org: |%010.5d|\n", -123);
	// r2 = ft_printf("my : |%010.5d|\n", -123);
	// printf("origin: %d, my: %d\n\n", r1, r2);

	r1 =    printf("org: |%2d|\n", -123);
	r2 = ft_printf("my : |%2d|\n", -123);
	printf("origin: %d, my: %d\n\n", r1, r2);
	r1 =    printf("org: |%.2d|\n", -123);
	r2 = ft_printf("my : |%.2d|\n", -123);
	printf("origin: %d, my: %d\n\n", r1, r2);
	r1 =    printf("org: |%1.2d|\n", -123);
	r2 = ft_printf("my : |%1.2d|\n", -123);
	printf("origin: %d, my: %d\n\n", r1, r2);
	r1 =    printf("org: |%2.1d|\n", -123);
	r2 = ft_printf("my : |%2.1d|\n", -123);
	printf("origin: %d, my: %d\n\n", r1, r2);
	r1 =    printf("org: |%-d|\n", -123);
	r2 = ft_printf("my : |%-d|\n", -123);
	printf("origin: %d, my: %d\n\n", r1, r2);
	r1 =    printf("org: |%0d|\n", -123);
	r2 = ft_printf("my : |%0d|\n", -123);
	printf("origin: %d, my: %d\n\n", r1, r2);
	r1 =    printf("org: |%-1d|\n", -123);
	r2 = ft_printf("my : |%-1d|\n", -123);
	printf("origin: %d, my: %d\n\n", r1, r2);
	r1 =    printf("org: |%-.1d|\n", -123);
	r2 = ft_printf("my : |%-.1d|\n", -123);
	printf("origin: %d, my: %d\n\n", r1, r2);
	r1 =    printf("org: |%-1.2d|\n", -123);
	r2 = ft_printf("my : |%-1.2d|\n", -123);
	printf("origin: %d, my: %d\n\n", r1, r2);
	r1 =    printf("org: |%-2.1d|\n", -123);
	r2 = ft_printf("my : |%-2.1d|\n", -123);
	printf("origin: %d, my: %d\n\n", r1, r2);
	r1 =    printf("org: |%01d|\n", -123);
	r2 = ft_printf("my : |%01d|\n", -123);
	printf("origin: %d, my: %d\n\n", r1, r2);
	r1 =    printf("org: |%0.1d|\n", -123);
	r2 = ft_printf("my : |%0.1d|\n", -123);
	printf("origin: %d, my: %d\n\n", r1, r2);
	r1 =    printf("org: |%01.2d|\n", -123);
	r2 = ft_printf("my : |%01.2d|\n", -123);
	printf("origin: %d, my: %d\n\n", r1, r2);
	r1 =    printf("org: |%02.1d|\n", -123);
	r2 = ft_printf("my : |%02.1d|\n", -123);
	printf("origin: %d, my: %d\n\n", r1, r2);
}
