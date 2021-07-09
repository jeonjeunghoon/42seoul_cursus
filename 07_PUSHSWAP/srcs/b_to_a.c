/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:57:42 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/07/09 20:02:52 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	recycle_stack_b(t_head *a_head, t_head *b_head, int *ra_rb_pa)
{
	int	i;

	i = 0;
	while (i < ra_rb_pa[0] && i < ra_rb_pa[1])
	{
		rrr(a_head, b_head);
		i++;
	}
	while (i < ra_rb_pa[0])
	{
		rra(a_head, 0);
		i++;
	}
	while (i < ra_rb_pa[1])
	{
		rrb(b_head, 0);
		i++;
	}
}

void	div_stack_b(t_head *a_head, t_head *b_head, int *pivot, int *ra_rb_pa)
{
	if (b_head->node->data < pivot[0])
	{
		rb(b_head, 0);
		ra_rb_pa[1]++;
	}
	else
	{
		pa(a_head, b_head);
		ra_rb_pa[2]++;
		if (a_head->node->data < pivot[1])
		{
			ra(a_head, 0);
			ra_rb_pa[0]++;
		}
	}
}

int	is_except_b(t_head *a_head, t_head *b_head, int range)
{
	if (range <= 3)
	{
		b_except(a_head, b_head, range);
		return (1);
	}
	return (0);
}

void	b_to_a(t_head *a_head, t_head *b_head, t_init *data, int range)
{
	int	pivot[2];
	int	ra_rb_pa[3];
	int	i;

	ra_rb_pa[0] = 0;
	ra_rb_pa[1] = 0;
	ra_rb_pa[2] = 0;
	if (is_except_b(a_head, b_head, range))
		return ;
	if ((find_pivot(b_head, pivot, range)) == 0)
		return ;
	i = 0;
	while (i < range)
	{
		div_stack_b(a_head, b_head, pivot, ra_rb_pa);
		i++;
	}
	a_to_b(a_head, b_head, data, ra_rb_pa[2] - ra_rb_pa[0]);
	recycle_stack_b(a_head, b_head, ra_rb_pa);
	a_to_b(a_head, b_head, data, ra_rb_pa[0]);
	b_to_a(a_head, b_head, data, ra_rb_pa[1]);
}
