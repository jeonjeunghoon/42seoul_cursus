/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 11:12:36 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/07/12 18:19:23 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	get_size(t_init *data, t_bundle_head head)
{
	int	size;

	size = 0;
	while (head.node != NULL)
	{
		head.node = head.node->next;
		size++;
	}
	data->size = size;
}

void	create_bundle_arr(t_init *data, t_bundle_head *bundle)
{
	int				i;
	t_bundle_node	*del_node;

	del_node = bundle->node;
	bundle->node = bundle->node->next;
	free(del_node);
	get_size(data, *bundle);
	data->bundle_arr = (char **)malloc(sizeof(char *) * (data->size + 1));
	if (!data->bundle_arr)
		ft_exit("Error\n");
	data->bundle_arr[data->size] = NULL;
	i = 0;
	while (i < data->size && data->bundle)
	{
		data->bundle_arr[i] = ft_strdup(bundle->node->num_ptr);
		i++;
		free(bundle->node->num_ptr);
		del_node = bundle->node;
		bundle->node = bundle->node->next;
		free(del_node);
	}
	free(data->bundle);
}

void	add_bundle(char *s, t_bundle_node *node)
{
	t_bundle_node	*add_node;

	add_node = (t_bundle_node *)malloc(sizeof(t_bundle_node));
	if (!add_node)
		ft_exit("Error\n");
	add_node->num_ptr = ft_strdup(s);
	if (add_node->num_ptr[0] == '\0')
		ft_exit("Error\n");
	add_node->next = NULL;
	while (node->next != NULL)
		node = node->next;
	node->next = add_node;
}

int	is_split(char *s)
{
	int	i;
	int	need_split;
	int	valid_split;

	need_split = 0;
	valid_split = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == ' ')
			need_split = 1;
		if (s[i] >= '0' && s[i] <= '9')
			valid_split = 1;
		i++;
	}
	if (need_split == 1 && valid_split == 1)
		return (1);
	else if (need_split == 1 && valid_split == 0)
		ft_exit("Error\n");
	return (0);
}

void	create_bundle(char **argv, t_init *data)
{
	char	**split_bundle;
	int		i;
	int		j;

	i = 1;
	while (argv[i])
	{
		if (is_split(argv[i]))
		{
			split_bundle = ft_split(argv[i], ' ');
			j = 0;
			while (split_bundle[j])
			{
				add_bundle(split_bundle[j], data->bundle->node);
				free(split_bundle[j]);
				j++;
			}
			free(split_bundle);
		}
		else
			add_bundle(argv[i], data->bundle->node);
		i++;
	}
}
