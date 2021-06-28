/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 23:45:32 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/06/28 16:24:01 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void		ft_exit(char *msg)
{
	write(1, msg, ft_strlen(msg));
	exit(0);
}

void		create_node_back(t_stack *lst, int *data)
{
	t_stack	*node;

	if (!lst)
		ft_exit("Error: create_node_back\n");
	if (!(node = (t_stack *)malloc(sizeof(t_stack))))
		ft_exit("Error: create_node_back\n");
	node->data = *data;
	node->next = NULL;
	lst->next = node;
}

void		ft_del_stack(t_stack *lst)
{
	lst->data = 0;
	lst->is_head = 0;
	lst->next = NULL;
	free(lst);
}

void		ft_push(t_stack **head, int data)
{
	t_stack	*node;

	if (!(node = (t_stack *)malloc(sizeof(t_stack))))
		ft_exit("Error: push\n");
	(*head)->data = data;
	(*head)->is_head = 0;
	node->next = (*head);
	node->is_head = 1;
	(*head) = node;
}

int			ft_pop(t_stack **head)
{
	t_stack	*head_temp;
	int		data;

	if ((*head)->is_head == 1 && (*head)->next == NULL)
		return (-42);
	head_temp = (*head);
	(*head) = (*head)->next;
	ft_del_stack(head_temp);
	data = (*head)->data;
	(*head)->data = 0;
	(*head)->is_head = 1;
	return (data);
}
