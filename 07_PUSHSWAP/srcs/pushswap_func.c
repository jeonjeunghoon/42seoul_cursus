/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 23:46:57 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/05/25 23:47:03 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void		sa(t_stack **a)
{
	element	first_data;
	element second_data;

	if ((*a)->is_head == 1 && (*a)->next == NULL)
	{
		printf("No Element in A\n");
		return ;
	}
	if ((*a)->next->next == NULL)
	{
		printf("Only One Element in A\n");
		return ;
	}
	first_data = ft_pop(a);
	second_data = ft_pop(a);
	ft_push(a, first_data);
	ft_push(a, second_data);
}

void		sb(t_stack **b)
{
	element	first_data;
	element	second_data;

	if ((*b)->is_head == 1 && (*b)->next == NULL)
	{
		printf("No Element in A\n");
		return ;
	}
	if ((*b)->next->next == NULL)
	{
		printf("Only One Element in A\n");
		return ;
	}
	first_data = ft_pop(b);
	second_data = ft_pop(b);
	ft_push(b, first_data);
	ft_push(b, second_data);
}

void		ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
}

void		pa(t_stack **a, t_stack **b)
{
	if ((*b)->is_head == 1 && (*b)->next == NULL)
	{
		printf("No Element in A\n");
		return ;
	}
	ft_push(a, ft_pop(b));
}

void		pb(t_stack **a, t_stack **b)
{
	if ((*a)->is_head == 1 && (*a)->next == NULL)
	{
		printf("No Element in A\n");
		return ;
	}
	ft_push(b, ft_pop(a));
}
