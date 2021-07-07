/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 23:49:19 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/07/07 17:49:21 by jeunjeon         ###   ########.fr       */
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

void		num_init(t_init *data)
{
	int		i;
	int		len;
	t_num	*num;

	len = 0;
	num = data->num_bundle;
	while (data->num_bundle)
	{
		data->num_bundle = data->num_bundle->next;
		len++;
	}
	data->num_bundle = num;
	if (!(data->num_arr = (int *)malloc(sizeof(int) * (len))))
		ft_exit("Error: num_init\n");
	i = 0;
	while (data->num_bundle)
	{
		(data->num_arr)[i] = ft_atoi(data->num_bundle->num_ptr);
		data->num_bundle = data->num_bundle->next;
		i++;
	}
	printf("\nlen == %d\n", len);
	for (int i = 0; i < len; i++)
		printf("num_arr[%d] == %d\n", i, data->num_arr[i]);
	for (;;)
	;
	if ((is_valid_num(data->num_arr, len) == 0))
		ft_exit("Error: num_init\n");
}

int			need_split(char *argv)
{
	int		i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] == ' ')
			break ;
		i++;
	}
	if (argv[i] == '\0')
		return (0);
	return (1);
}

void		create_num_back(char *s, t_init *data)
{
	t_num	*new_node;

	if (!s)
		return ;
	if (!(new_node = (t_num *)malloc(sizeof(t_num))))
		ft_exit("Error: create_num_back\n");
	
}

int			create_num(int argc, char **argv, t_init *data)
{
	t_num	*head;
	t_num	*new_node;
	char	**bundle;
	int		i;
	int		j;

	head = data->num_bundle;
	new_node = data->num_bundle;
	i = 1;
	while (argv[i])
	{
		if (need_split(argv[i]))
		{
			bundle = ft_split(argv[i], ' ');
			j = 0;
			while (bundle[j])
			{
				if (!(data->num_bundle = (t_num *)malloc(sizeof(t_num))))
					ft_exit("Error: create_num\n");
				data->num_bundle->num_ptr = NULL;
				data->num_bundle->num_ptr = ft_strdup(bundle[j]);
				while (data->num_bundle->next != NULL)
					data->num_bundle = data->num_bundle->next;
				
				free(bundle[j]);
				j++;
			}
			free(bundle);
		}
		else
		{
			if (!(data->num_bundle = (t_num *)malloc(sizeof(t_num))))
				ft_exit("Error: create_num\n");
			data->num_bundle->num_ptr = NULL;
			data->num_bundle->next = NULL;
			data->num_bundle->num_ptr = ft_strdup(argv[i]);
			data->num_bundle = data->num_bundle->next;
		}
		i++;
	}
	data->num_bundle = head;
	while (data->num_bundle)
	{
		printf("num_bundle == %s\n", data->num_bundle->num_ptr);
		data->num_bundle = data->num_bundle->next;
	}
	for (;;)
	;
	return (1);
}
