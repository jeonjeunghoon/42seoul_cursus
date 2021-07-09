/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_except.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 16:59:40 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/07/09 19:43:24 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	a_one(t_head *head)
{
	if (head->node->next->data > head->node->next->next->data)
	{
		ra(head, 0);
		sa(head, 0);
		rra(head, 0);
	}
}

void	a_two(t_head *head)
{
	if (head->node->data > head->node->next->data && \
		head->node->data < head->node->next->next->data && \
		head->node->next->data < head->node->next->next->data)
		sa(head, 0);
	else if (head->node->data < head->node->next->data && \
			head->node->data > head->node->next->next->data && \
			head->node->next->data > head->node->next->next->data)
	{
		ra(head, 0);
		sa(head, 0);
		rra(head, 0);
		sa(head, 0);
	}
}

void	a_three(t_head *head)
{
	if (head->node->next->data < head->node->next->next->data)
	{
		sa(head, 0);
		ra(head, 0);
		sa(head, 0);
		rra(head, 0);
	}
	else
	{
		sa(head, 0);
		ra(head, 0);
		sa(head, 0);
		rra(head, 0);
		sa(head, 0);
	}
}

void	a_size_three(t_head *head)
{
	if (head->node->data < head->node->next->data && \
		head->node->data < head->node->next->next->data)
		a_one(head);
	else if (head->node->data > head->node->next->data && \
			head->node->data > head->node->next->next->data)
		a_three(head);
	else
		a_two(head);
}

void	a_except(t_head *head, int range)
{
	if (range == 1)
		return ;
	else if (range == 2 && head->node->data > head->node->next->data)
		sa(head, 0);
	else if (range == 3)
		a_size_three(head);
}
