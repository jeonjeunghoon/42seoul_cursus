/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 19:36:45 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/12/11 17:35:53 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*res;

	if (!lst)
		return (NULL);
	if (!(res = ft_lstnew(f(lst->content))))
		return (NULL);
	temp = res;
	while ((lst = lst->next))
	{
		if (!(ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&res, del);
			return (NULL);
		}
		ft_lstadd_back(&temp, ft_lstnew(f(lst->content)));
	}
	return (res);
}
