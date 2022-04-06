/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 16:04:51 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/04/06 14:12:22 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tail;

	tail = NULL;
	if (*lst == NULL)
	{
		*lst = new;
		new->next = NULL;
		new->pre = NULL;
	}
	else
	{
		tail = *lst;
		while (tail->next != NULL)
			tail = tail->next;
		tail->next = new;
		new->pre = tail;
		new->next = NULL;
	}
}
