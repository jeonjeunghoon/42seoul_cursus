/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_func2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 23:47:45 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/05/26 00:04:46 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void		ra(t_stack **a)
{
	t_stack	*head;
	t_stack *first_node;

	head = (*a);
	if (head->is_head == 1 && head->next == NULL)
		return ;
	first_node = head->next;
	head->next = first_node->next;
	while (head->next != NULL)
		head = head->next;
	head->next = first_node;
	first_node->next = NULL;
}

void		rb(t_stack **b)
{
	t_stack	*head;
	t_stack *first_node;

	head = (*b);
	if (head->is_head == 1 && head->next == NULL)
		return ;
	first_node = head->next;
	head->next = first_node->next;
	while (head->next != NULL)
		head = head->next;
	head->next = first_node;
	first_node->next = NULL;
}

void		rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}
