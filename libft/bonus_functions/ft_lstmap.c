/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 01:01:58 by yohlee            #+#    #+#             */
/*   Updated: 2020/03/02 01:49:49 by yohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** *(*f): func used to iterate.
**
** malloc, free.
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*res;
	void	*temp;

	if (!f || !del)
		return (NULL);
	res = 0;
	while (lst)
	{
		temp = (*f)(lst->content);
		if (!(new = ft_lstnew(temp)))
		{
			ft_lstclear(&res, del);
			free(temp);
			return (NULL);
		}
		ft_lstadd_back(&res, new);
		lst = lst->next;
	}
	return (res);
}
