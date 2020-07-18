/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 18:43:11 by yohlee            #+#    #+#             */
/*   Updated: 2020/07/18 23:29:25 by yohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_pwd(t_arg *a, int newline)
{
	if (!(getcwd(a->pwd, 1024)))
	{
		chdir("..");
		if (!(getcwd(a->pwd, 1024)))
		{
			write(2, "pwd error : ", 12);
			write(2, strerror(errno), ft_strlen(strerror(errno)));
			write(2, "\n", 1);
			exit(-1);
		}
	}
	if (!newline)
		write(1, a->pwd, ft_strlen(a->pwd));
	if (newline)
	{
		write(a->fd, a->pwd, ft_strlen(a->pwd));
		write(a->fd, "\n", 1);
	}
	return (1);
}
