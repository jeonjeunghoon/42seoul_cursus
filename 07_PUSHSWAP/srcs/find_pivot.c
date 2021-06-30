/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:41:05 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/06/30 11:50:13 by jeunjeon         ###   ########.fr       */
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

void			find_pivot(t_init *data, int size)
{
	int			pivot;
	int			*num_ptr;
	int			i;

	if (!(num_ptr = (int *)malloc(sizeof(int) * size)))
		ft_exit("Error: find_pivot\n");
	i = -1;
	while (++i < size)
		num_ptr[i] = data->num_arr[i];
	quick_sort(num_ptr, 0, size - 1);
	i = 0;
	pivot = num_ptr[size / 3];
	while (data->num_arr[i] != pivot)
		i++;
	data->small_pivot = data->num_arr[i];
	pivot = num_ptr[size * 2 / 3];
	i = 0;
	while (data->num_arr[i] != pivot)
		i++;
	data->large_pivot = data->num_arr[i];
}
