/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:41:05 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/06/30 14:35:27 by jeunjeon         ###   ########.fr       */
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

void			reset_arr(t_head head, t_init *data)
{
	int			i;

	free(data->num_arr);
	if (!(data->num_arr = (int *)malloc(sizeof(int) * head.size)))
		ft_exit("Error: reset_arr\n");
	i = 0;
	while (i < head.size)
	{
		data->num_arr[i] = head.node->data;
		head.node = head.node->next;
		i++;
	}
}

void			find_pivot(t_head *head, t_init *data, int *pivot)
{
	int			i;

	reset_arr(*head, data);
	i = 0;
	quick_sort(data->num_arr, 0, head->size - 1);
	pivot[0] = data->num_arr[head->size / 3];
	pivot[1] = data->num_arr[head->size * 2 / 3];
}
