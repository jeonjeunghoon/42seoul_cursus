/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 17:21:09 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/06/29 17:27:12 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int				ft_partition(t_head *a_head, t_head *b_head, int left, int right)
{
	int			pivot;
	int			next_pivot;
	int			compare_data;

	pivot = right;
	next_pivot = left - 1;
	while (left < right)
	{
		if (pivot < compare_data)
		{
			ra(a_head);
			next_pivot++;
		}
		else if (pivot > compare_data)
			pb(a_head, b_head);
		left++;
	}
	
	return (next_pivot + 1);
}

void			push_swap(t_head *a_head, t_head *b_head, int left, int right)
{
	int			pivot;

	pivot = 0;
	if (left < right)
	{
		pivot = ft_partition(a_head, b_head, left, right);
		push_swap(a_head, b_head, left, pivot - 1);
		push_swap(a_head, b_head, pivot + 1, right);
	}
}
