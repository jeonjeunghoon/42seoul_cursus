/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:41:05 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/07/03 22:27:54 by jeunjeon         ###   ########.fr       */
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

void			reset_arr(t_head *head, t_init *data)
{
	// write(1, "@@@@@\n", 6);
	int			i;
	t_node		*curr;

	free(data->num_arr);
	if (!(data->num_arr = (int *)malloc(sizeof(int) * head->size)))
		ft_exit("Error: reset_arr\n");
	curr = head->node;
	i = 0;
	while (i < head->size)
	{
		data->num_arr[i] = curr->data;
		curr = curr->next;
		i++;
	}
}

int				find_pivot(t_head *head, t_init *data, int *pivot)
{
	if (head->size < 0)
		return (0);
	reset_arr(head, data);
	quick_sort(data->num_arr, 0, head->size - 1);
	pivot[0] = data->num_arr[head->size / 3];
	pivot[1] = data->num_arr[head->size * 2 / 3];
	return (1);
}
