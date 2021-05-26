/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:41:05 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/05/26 23:49:32 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void			ft_swap(int *a, int *b)
{
	int			temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int				partition(int *num_arr, int left, int right)
{
	int			i;
	int			pivot;

	i = left - 1;
	pivot = num_arr[right];
	while (left < right)
	{
		if (pivot > num_arr[left])
		{
			i++;
			ft_swap(&(num_arr[i]), &(num_arr[left]));
		}
		left++;
	}
	ft_swap(&(num_arr[right]), &(num_arr[i + 1]));
	return (i + 1);
}

void			quick_sort(int *num_arr, int left, int right)
{
	int			pivot;

	pivot = 0;
	if (left < right)
	{
		pivot = partition(num_arr, left, right);
		quick_sort(num_arr, left, pivot - 1);
		quick_sort(num_arr, pivot + 1, right);
	}
}

void			find_pivot(t_init *data)
{
	quick_sort(data->num_arr, 0, data->len_of_node - 1);
	data->pivot = data->len_of_node / 2;
}

int				ft_partition(t_stack *a, t_stack *b, int left, int right)
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
			ra(&a);
			next_pivot++;
		}
		else if (pivot > compare_data)
			pb(&a, &b);
		left++;
	}
	
	return (next_pivot + 1);
}

void			ft_quick_sort(t_stack *a, t_stack *b, int left, int right)
{
	int			pivot;

	pivot = 0;
	if (left < right)
	{
		pivot = ft_partition(a, b, left, right);
		ft_quick_sort(a, b, left, pivot - 1);
		ft_quick_sort(a, b, pivot + 1, right);
	}
}
