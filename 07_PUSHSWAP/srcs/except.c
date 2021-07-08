/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   except.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 20:02:59 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/07/08 20:40:32 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void		except_size_three(t_head *head)
{
	if (head->node->data < head->node->next->data && \
		head->node->data < head->node->next->next->data)
	{
		if (head->node->next->data > head->node->next->next->data)
		{
			rra(head, 0);
			sa(head, 0);
		}
	}
	else if (head->node->data > head->node->next->data && \
			head->node->data > head->node->next->next->data)
	{
		if (head->node->next->data < head->node->next->next->data)
			ra(head, 0);
		else
		{
			sa(head, 0);
			rra(head, 0);
		}
	}
	else
	{
		if (head->node->data > head->node->next->data && \
			head->node->data < head->node->next->next->data && \
			head->node->next->data < head->node->next->next->data)
			sa(head, 0);
		else if (head->node->data < head->node->next->data && \
				head->node->data > head->node->next->next->data && \
				head->node->next->data > head->node->next->next->data)
			rra(head, 0);
	}
}

int			find_mid_pivot(t_head head)
{
	int		*num_arr;
	int		i;

	num_arr = (int *)malloc(sizeof(int) * 5);
	i = 0;
	while (i < 5)
	{
		num_arr[i] = head.node->data;
		head.node = head.node->next;
		i++;
	}
	quick_sort(num_arr, 0, 4);
	free(num_arr);
	return (num_arr[2]);
}

void		except_size_five(t_head *a, t_head *b)
{
	int		pivot;
	int		time_pb;
	int		time_ra;

	pivot = find_mid_pivot(*a);
	time_pb = 0;
	time_ra = 0;
	while (time_pb < 2)
	{
		if (a->node->data >= pivot)
		{
			ra(a, 0);
			time_ra++;
		}
		else
		{
			pb(a, b);
			time_pb++;
		}
	}
	if (a->size > 5)
	{
		while (time_ra-- > 0)
			rra(a, 0);
		a_except(a, 3);
	}
	else
		except_size_three(a);
	b_except(a, b, 2);
}
