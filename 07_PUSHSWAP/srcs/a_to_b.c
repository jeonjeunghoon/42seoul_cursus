/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 17:21:09 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/07/09 19:59:07 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	recycle_stack_a(t_head *a_head, t_head *b_head, int *ra_rb_pb)
{
	int	i;

	i = 0;
	while (i < ra_rb_pb[0] && i < ra_rb_pb[1])
	{
		rrr(a_head, b_head);
		i++;
	}
	while (i < ra_rb_pb[0])
	{
		rra(a_head, 0);
		i++;
	}
	while (i < ra_rb_pb[1])
	{
		rrb(b_head, 0);
		i++;
	}
}

void	div_stack_a(t_head *a_head, t_head *b_head, int *pivot, int *ra_rb_pb)
{
	if (a_head->node->data >= pivot[1])
	{
		ra(a_head, 0);
		ra_rb_pb[0]++;
	}
	else
	{
		pb(a_head, b_head);
		ra_rb_pb[2]++;
		if (b_head->node->data >= pivot[0])
		{
			rb(b_head, 0);
			ra_rb_pb[1]++;
		}
	}
}

int	is_except_a(t_head *a_head, t_head *b_head, int range)
{
	if (range <= 3 || range == 5)
	{
		if (range <= 3)
			a_except(a_head, range);
		else
			except_size_five(a_head, b_head);
		return (1);
	}
	return (0);
}

void	a_to_b(t_head *a_head, t_head *b_head, t_init *data, int range)
{
	int	pivot[2];
	int	ra_rb_pb[3];
	int	i;

	ra_rb_pb[0] = 0;
	ra_rb_pb[1] = 0;
	ra_rb_pb[2] = 0;
	if (is_except_a(a_head, b_head, range))
		return ;
	if ((find_pivot(a_head, pivot, range)) == 0)
		return ;
	i = 0;
	while (i < range)
	{
		div_stack_a(a_head, b_head, pivot, ra_rb_pb);
		i++;
	}
	recycle_stack_a(a_head, b_head, ra_rb_pb);
	a_to_b(a_head, b_head, data, ra_rb_pb[0]);
	b_to_a(a_head, b_head, data, ra_rb_pb[1]);
	b_to_a(a_head, b_head, data, ra_rb_pb[2] - ra_rb_pb[1]);
}
