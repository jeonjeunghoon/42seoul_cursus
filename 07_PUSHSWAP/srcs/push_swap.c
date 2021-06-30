/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 17:21:09 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/06/30 11:54:28 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void			count_size(t_head *a_head, t_head *b_head, t_init *data)
{

}

void			b_to_a(t_head *a_head, t_head *b_head, t_init *data, int r)
{
	int			ra_time;
	int			rb_time;
	int			pa_time;

	ra_time = 0;
	rb_time = 0;
	pa_time = 0;
	if (r < 3)
	{
		// 정렬 or pa
		return ;
	}
	find_pivot(data, b_head->size);
	while (r--)
	{
		if (b_head->node->data < data->small_pivot)
		{
			rb(b_head);
			rb_time++;
		}
		else
		{
			pa(a_head, b_head);
			pa_time++;
			if (b_head->node->data > data->large_pivot)
			{
				ra(a_head);
				ra_time++;
			}
		}
		count_size(a_head, b_head, data);
		a_to_b(a_head, b_head, data, pa_time - ra_time);
	}
	for (int i = 0; i < ra_time && i < rb_time; i++)
		rrr(a_head, b_head);
	a_to_b(a_head, b_head, data, rb_time);
	b_to_a(a_head, b_head, data, ra_time);
}

void			a_to_b(t_head *a_head, t_head *b_head, t_init *data, int r)
{
	int			time_ra;
	int			time_rb;
	int			time_pb;

	time_ra = 0;
	time_rb = 0;
	time_pb = 0;
	if (r < 3)
	{
		// 정렬
		return ;
	}
	find_pivot(data, a_head->size);
	while (r--)
	{
		if (a_head->node->data > data->large_pivot)
		{
			ra(a_head);
			time_ra++;
		}
		else
		{
			pb(a_head, b_head);
			time_pb++;
			if (b_head->node->data > data->small_pivot)
			{
				rb(b_head);
				time_rb++;
			}
		}
	}
	for (int i = 0; i < ra && i < rb; i++)
		rrr(a_head, b_head);
	count_size(a_head, b_head, data);
	a_to_b(a_head, b_head, data, time_ra);
	b_to_a(a_head, b_head, data, time_rb);
	b_to_a(a_head, b_head, data, time_pb - time_rb);
}
