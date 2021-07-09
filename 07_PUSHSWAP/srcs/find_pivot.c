/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:41:05 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/07/09 17:06:11 by jeunjeon         ###   ########.fr       */
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

void			reset_arr(t_head *head, int *arr, int range)
{
	int			i;
	t_node		*curr;

	curr = head->node;
	i = 0;
	while (i < range && curr)
	{
		arr[i] = curr->data;
		curr = curr->next;
		i++;
	}
}

int				find_pivot(t_head *head, int *pivot, int range)
{
	int			*arr;

	if (head->size <= 3 || range <= 3)
		return (0);
	if (!(arr = (int *)malloc(sizeof(int) * range)))
		ft_exit("Error\n");
	reset_arr(head, arr, range);
	quick_sort(arr, 0, range - 1);
	pivot[0] = arr[0 + (range / 3)];
	pivot[1] = arr[range - 1 - range / 3];
	free(arr);
	return (1);
}
