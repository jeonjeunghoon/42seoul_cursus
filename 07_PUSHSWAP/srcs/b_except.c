/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_except.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 16:59:57 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/07/12 14:45:12 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	b_one(t_head *a_head, t_head *b_head)
{
	if (b_head->node->next->data > b_head->node->next->next->data)
		rb(b_head, 0);
	else
	{
		rb(b_head, 0);
		sb(b_head, 0);
	}
	pa(a_head, b_head);
	pa(a_head, b_head);
	rrb(b_head, 0);
	pa(a_head, b_head);
}

void	b_two(t_head *a_head, t_head *b_head)
{
	if (b_head->node->data > b_head->node->next->data && \
		b_head->node->next->data < b_head->node->next->next->data)
	{
		rb(b_head, 0);
		sb(b_head, 0);
		pa(a_head, b_head);
		rrb(b_head, 0);
	}
	else if (b_head->node->data < b_head->node->next->data && \
			b_head->node->next->data > b_head->node->next->next->data)
	{
		sb(b_head, 0);
		pa(a_head, b_head);
	}
	pa(a_head, b_head);
	pa(a_head, b_head);
}

void	b_three(t_head *a_head, t_head *b_head)
{
	if (b_head->node->next->data < b_head->node->next->next->data)
	{
		pa(a_head, b_head);
		sb(b_head, 0);
	}
	else
		pa(a_head, b_head);
	pa(a_head, b_head);
	pa(a_head, b_head);
}

void	b_size_three(t_head *a_head, t_head *b_head)
{
	if (b_head->node->data < b_head->node->next->data && \
		b_head->node->data < b_head->node->next->next->data)
		b_one(a_head, b_head);
	else if (b_head->node->data > b_head->node->next->data && \
			b_head->node->data > b_head->node->next->next->data)
		b_three(a_head, b_head);
	else
		b_two(a_head, b_head);
}

void	b_except(t_head *a_head, t_head *b_head, int range)
{
	if (range == 1)
		pa(a_head, b_head);
	else if (range == 2)
	{
		if (b_head->node->data < b_head->node->next->data)
			sb(b_head, 0);
		pa(a_head, b_head);
		pa(a_head, b_head);
	}
	else if (range == 3)
		b_size_three(a_head, b_head);
}
