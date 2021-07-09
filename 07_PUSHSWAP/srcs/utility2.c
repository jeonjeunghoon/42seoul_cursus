/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 23:49:19 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/07/09 18:48:14 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

size_t	ft_strlen(const char *s)
{
	int	res;

	res = 0;
	if (!s)
		return (0);
	while (((unsigned char *)s)[res])
		res++;
	return (res);
}

int	is_valid_num(int *num_arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (num_arr[i] == num_arr[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	num_init(t_init *data)
{
	int	i;

	data->num_arr = (int *)malloc(sizeof(int) * (data->size));
	if (!data->num_arr)
		ft_exit("Error\n");
	i = 0;
	while (data->bundle_arr[i])
	{
		(data->num_arr)[i] = ft_atoi(data->bundle_arr[i]);
		i++;
	}
	i = 0;
	if ((is_valid_num(data->num_arr, data->size) == 0))
		ft_exit("Error\n");
}

int	is_valid_arg(t_init *data)
{
	int	i;
	int	j;

	i = 1;
	while (data->bundle_arr[i])
	{
		j = 0;
		while (data->bundle_arr[i][j])
		{
			if ((data->bundle_arr[i][j] == '-' || \
				data->bundle_arr[i][j] == '+') && \
				j == 0)
				j++;
			else if (data->bundle_arr[i][j] >= '0' && \
					data->bundle_arr[i][j] <= '9')
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}
