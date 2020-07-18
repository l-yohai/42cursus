/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 18:39:36 by yohlee            #+#    #+#             */
/*   Updated: 2020/07/18 23:02:52 by yohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_exit(t_arg *a)
{
	char	**lines;
	int		num;

	lines = ft_split(a->line, ' ');
	if (lines[1])
	{
		if (lines[2])
		{
			ft_free(lines);
			write(2, "exit: too many arguments\n", 25);
			a->ret = 1;
			return (1);
		}
		num = ft_atoi(lines[1]);
		ft_free(lines);
		exit(num);
	}
	ft_free(lines);
	exit(a->ret);
}
