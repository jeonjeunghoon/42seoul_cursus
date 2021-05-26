/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_func3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 23:48:21 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/05/26 14:50:39 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void		rra(t_stack **a)
{
	t_stack	*head;
	t_stack	*last_node;

	head = (*a);
	if (head->is_head == 1 && head->next == NULL)
		return ;
	while (head->next->next != NULL)
	{
		head = head->next;
	}
	last_node = head->next;
	head->next = NULL;
	last_node->next = (*a)->next;
	(*a)->next = last_node;
}

void		rrb(t_stack **b)
{
	t_stack	*head;
	t_stack	*last_node;

	head = (*b);
	if (head->is_head == 1 && head->next == NULL)
		return ;
	while (head->next->next != NULL)
		head = head->next;
	last_node = head->next;
	head->next = NULL;
	last_node->next = (*b)->next;
	(*b)->next = last_node;
}

void		rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
}
