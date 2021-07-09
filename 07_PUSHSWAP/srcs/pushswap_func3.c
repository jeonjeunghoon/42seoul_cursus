/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_func3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 23:48:21 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/07/08 21:17:41 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rra(t_head *a_head, int is_rrr)
{
	t_node	*curr;
	t_node	*bottom_node;

	if (a_head->node == NULL)
		return ;
	if (a_head->node->next == NULL)
		return ;
	curr = a_head->node;
	while (curr->next->next != NULL)
		curr = curr->next;
	bottom_node = curr->next;
	curr->next = NULL;
	bottom_node->next = a_head->node;
	a_head->node = bottom_node;
	if (is_rrr != 1)
		write(1, "rra\n", 4);
}

void	rrb(t_head *b_head, int is_rrr)
{
	t_node	*curr;
	t_node	*bottom_node;

	if (b_head->node == NULL)
		return ;
	if (b_head->node->next == NULL)
		return ;
	curr = b_head->node;
	while (curr->next->next != NULL)
		curr = curr->next;
	bottom_node = curr->next;
	curr->next = NULL;
	bottom_node->next = b_head->node;
	b_head->node = bottom_node;
	if (is_rrr != 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_head *a_head, t_head *b_head)
{
	rra(a_head, 1);
	rrb(b_head, 1);
	write(1, "rrr\n", 4);
}
