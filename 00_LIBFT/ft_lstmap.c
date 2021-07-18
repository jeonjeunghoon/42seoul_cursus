/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 19:36:45 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/07/17 18:20:52 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*res;

	if (!lst)
		return (NULL);
	res = ft_lstnew(f(lst->content));
	if (!res)
		return (NULL);
	head = res;
	while (lst)
	{
		if (!(ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&res, del);
			return (NULL);
		}
		ft_lstadd_back(&head, ft_lstnew(f(lst->content)));
		lst = lst->next;
	}
	return (res);
}
