/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:57:42 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/07/12 17:26:18 by jeunjeon         ###   ########.fr       */
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

void	b_except_five(t_head *a_head, t_head *b_head)
{
	int	pivot;
	int	pa_rb[2];

	pivot = find_mid_pivot(*b_head);
	pa_rb[0] = 0;
	pa_rb[1] = 0;
	while (pa_rb[0] < 3)
	{
		if (b_head->node->data < pivot)
		{
			rb(b_head, 0);
			pa_rb[1]++;
		}
		else
		{
			pa(a_head, b_head);
			pa_rb[0]++;
		}
	}
	a_except(a_head, 3);
	while (pa_rb[1]--)
		rrb(b_head, 0);
	b_except(a_head, b_head, 2);
}

int	is_except_b(t_head *a_head, t_head *b_head, int range)
{
	if (range <= 3 || range == 5)
	{
		if (range <= 3)
			b_except(a_head, b_head, range);
		else
			b_except_five(a_head, b_head);
		return (1);
	}
	return (0);
}

void	b_to_a(t_stack *stack, t_init *data, int range, int *cnt)
{
	int	pivot[2];
	int	ra_rb_pa[3];
	int	i;

	ra_rb_pa[0] = 0;
	ra_rb_pa[1] = 0;
	ra_rb_pa[2] = 0;
	(*cnt)++;
	if (is_except_b(stack->a, stack->b, range))
		return ;
	if ((find_pivot(stack->b, pivot, range)) == 0)
		return ;
	i = 0;
	while (i < range)
	{
		div_stack_b(stack->a, stack->b, pivot, ra_rb_pa);
		i++;
	}
	a_to_b(stack, data, ra_rb_pa[2] - ra_rb_pa[0], cnt);
	recycle_stack_b(stack->a, stack->b, ra_rb_pa);
	a_to_b(stack, data, ra_rb_pa[0], cnt);
	b_to_a(stack, data, ra_rb_pa[1], cnt);
}
