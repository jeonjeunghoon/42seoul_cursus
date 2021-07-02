/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 23:46:57 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/07/02 17:05:18 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void		sa(t_head *head, int is_ss)
{
	int		first_data;
	int		second_data;

	if (head->node == NULL)
		return ;
	if (head->node->next == NULL)
		return ;
	first_data = ft_pop(head);
	second_data = ft_pop(head);
	ft_push(head, first_data);
	ft_push(head, second_data);
	if (is_ss != 1)
	{
		times++;
		write(1, "sa\n", 3);
	}
}

void		sb(t_head *head, int is_ss)
{
	int		first_data;
	int		second_data;

	if (head->node == NULL)
		return ;
	if (head->node->next == NULL)
		return ;
	first_data = ft_pop(head);
	second_data = ft_pop(head);
	ft_push(head, first_data);
	ft_push(head, second_data);
	if (is_ss != 1)
	{
		times++;
		write(1, "sb\n", 3);
	}
}

void		ss(t_head *a_head, t_head *b_head)
{
	sa(a_head, 1);
	sb(b_head, 1);
	times++;
	write(1, "ss\n", 3);
}

void		pa(t_head *a_head, t_head *b_head)
{
	if (b_head->node == NULL)
		return ;
	ft_push(a_head, ft_pop(b_head));
	a_head->size++;
	b_head->size--;
	if (a_head->size == 1)
		a_head->node->next = NULL;
	times++;
	write(1, "pa\n", 3);
}

void		pb(t_head *a_head, t_head *b_head)
{
	if (a_head->node == NULL)
		return ;
	ft_push(b_head, ft_pop(a_head));
	a_head->size--;
	b_head->size++;
	if (b_head->size == 1)
		b_head->node->next = NULL;
	times++;
	write(1, "pb\n", 3);
}
