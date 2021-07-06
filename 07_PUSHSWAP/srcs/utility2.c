/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 23:45:32 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/07/06 15:17:54 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void		ft_exit(char *msg)
{
	write(1, msg, ft_strlen(msg));
	exit(0);
}

void		ft_push(t_head *head, int data)
{
	t_node	*new_node;

	if (!(new_node = (t_node *)malloc(sizeof(t_node))))
		ft_exit("Error: push\n");
	new_node->data = data;
	new_node->next = head->node;
	head->node = new_node;
}

int			ft_pop(t_head *head)
{
	t_node	*del_node;
	int		data;

	if (!head->node)
		return (0);
	del_node = head->node;
	data = del_node->data;
	head->node = del_node->next;
	ft_del_node(del_node);
	return (data);
}

void		create_node_back(t_node *node, int data)
{
	t_node	*new_node;

	if (!node)
		ft_exit("Error: create_node_back\n");
	if (!(new_node = (t_node *)malloc(sizeof(t_node))))
		ft_exit("Error: create_node_back\n");
	new_node->data = data;
	new_node->next = NULL;
	while (node->next != NULL)
		node = node->next;
	node->next = new_node;
}

void		ft_del_node(t_node *node)
{
	node->data = 0;
	node->next = NULL;
	free(node);
}
