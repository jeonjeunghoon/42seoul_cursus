/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 23:49:19 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/06/28 16:44:13 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

size_t		ft_strlen(const char *s)
{
	int		res;

	res = 0;
	if (!s)
		return (0);
	while (((unsigned char *)s)[res])
		res++;
	return (res);
}

int			is_valid_num(int *num_arr, int size)
{
	int		i;
	int		j;

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

void		num_init(int argc, char **argv, t_init *data)
{
	int		i;

	if (!(data->num_arr = (int *)malloc(sizeof(int) * (argc - 1))))
		ft_exit("Error: num_init\n");
	i = 1;
	while (argv[i])
	{
		(data->num_arr)[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	if ((is_valid_num(data->num_arr, argc - 1) == 0))
		ft_exit("Error: num_init\n");
}

int			is_valid_arg(int argc, char **argv)
{
	int		i;
	int		j;

	if (argc < 2)
		return (0);
	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] == '-' || argv[i][j] == '+') && j == 0)
				j++;
			if (argv[i][j] >= '0' && argv[i][j] <= '9')
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}
