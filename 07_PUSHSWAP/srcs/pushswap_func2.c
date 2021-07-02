/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_func2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 23:47:45 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/07/02 17:02:38 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void		ra(t_head *a_head, int is_rr)
{
	t_node	*curr;
	t_node	*top_node;

	if (a_head == NULL)
		return ;
	if (a_head->node == NULL)
		return ;
	if (a_head->node->next == NULL)
		return ;
	top_node = a_head->node;
	a_head->node = top_node->next;
	curr = a_head->node;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = top_node;
	top_node->next = NULL;
	if (is_rr != 1)
	{
		times++;
		write(1, "ra\n", 3);
	}
}

void		rb(t_head *b_head, int is_rr)
{
	t_node	*curr;
	t_node	*top_node;

	if (b_head == NULL)
		return ;
	if (b_head->node == NULL)
		return ;
	if (b_head->node->next == NULL)
		return ;
	top_node = b_head->node;
	b_head->node = top_node->next;
	curr = b_head->node;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = top_node;
	top_node->next = NULL;
	if (is_rr != 1)
	{
		times++;
		write(1, "rb\n", 3);
	}
}

void		rr(t_head *a_head, t_head *b_head)
{
	ra(a_head, 1);
	rb(b_head, 1);
	times++;
	write(1, "rr\n", 3);
}
