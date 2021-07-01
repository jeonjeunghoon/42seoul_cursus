/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 17:21:09 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/07/01 17:50:46 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void			except_three(t_head *head)
{
	
}

void			b_except(t_head *a_head, t_head *b_head, int range)
{
	if (!b_head->node)
		return ;
	if (range == 1)
	{
		pa(a_head, b_head);
		return ;
	}
	else if (range == 2)
	{
		if (b_head->node->data < b_head->node->next->data)
			sb(b_head, 0);
		pa(a_head, b_head);
		pa(a_head, b_head);
	}
	else if (range == 3)
	{
		
	}
}

void			a_except(t_head *head, int range)
{
	if (!head->node)
		return ;
	if (range == 1)
		return ;
	else if (range == 2)
	{
		if (head->node->data > head->node->next->data)
			sa(head, 0);
	}
	else if (range == 3)
	{
		
	}
}

void			b_to_a(t_head *a_head, t_head *b_head, t_init *data, int range)
{
	int			pivot[2];
	int			time_ra;
	int			time_rb;
	int			time_pa;

	time_ra = 0;
	time_rb = 0;
	time_pa = 0;
	if (range < 3)
	{
		b_except(a_head, b_head, range);
		return ;
	}
	find_pivot(b_head, data, pivot);
	while (range--)
	{
		if (b_head->node->data < pivot[0])
		{
			rb(b_head, 0);
			time_rb++;
		}
		else
		{
			pa(a_head, b_head);
			time_pa++;
			if (b_head->node->data >= pivot[1])
			{
				ra(a_head, 0);
				time_ra++;
			}
		}
		a_to_b(a_head, b_head, data, time_pa - time_ra);
	}
	int i = 0;
	while (i < time_ra && i < time_rb)
	{
		rrr(a_head, b_head);
		i++;
	}
	while (i < time_ra)
	{
		rra(a_head, 0);
		i++;
	}
	while (i < time_rb)
	{
		rrb(b_head, 0);
		i++;
	}
	a_to_b(a_head, b_head, data, time_rb);
	b_to_a(a_head, b_head, data, time_ra);
}

void			a_to_b(t_head *a_head, t_head *b_head, t_init *data, int range)
{
	int			pivot[2];
	int			time_ra;
	int			time_rb;
	int			time_pb;

	time_ra = 0;
	time_rb = 0;
	time_pb = 0;
	if (range < 3)
	{
		a_except(a_head, range);
		return ;
	}
	find_pivot(a_head, data, pivot);
	while (range--)
	{
		if (a_head->node->data >= pivot[1])
		{
			ra(a_head, 0);
			time_ra++;
		}
		else
		{
			pb(a_head, b_head);
			time_pb++;
			if (b_head->node->data >= pivot[0])
			{
				rb(b_head, 0);
				time_rb++;
			}
		}
	}
	int i = 0;
	while (i < time_ra && i < time_rb)
	{
		rrr(a_head, b_head);
		i++;
	}
	while (i < time_ra)
	{
		rra(a_head, 0);
		i++;
	}
	while (i < time_rb)
	{
		rrb(b_head, 0);
		i++;
	}
	a_to_b(a_head, b_head, data, time_ra);
	b_to_a(a_head, b_head, data, time_rb);
	b_to_a(a_head, b_head, data, time_pb - time_rb);
}
