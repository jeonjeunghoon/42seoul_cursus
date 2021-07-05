/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 17:21:09 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/07/05 18:12:13 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void			b_except_three(t_head *a_head, t_head *b_head)
{
	if (b_head->node->data < b_head->node->next->data && \
		b_head->node->data < b_head->node->next->next->data)
	{
		if (b_head->node->next->data > b_head->node->next->next->data)
			rb(b_head, 0);
		else
		{
			rb(b_head, 0);
			sb(b_head, 0);
		}
			pa(a_head, b_head);
			pa(a_head, b_head);
			rrb(b_head, 0);
			pa(a_head, b_head);
	}
	else if (b_head->node->data > b_head->node->next->data && \
			b_head->node->data > b_head->node->next->next->data)
	{
		if (b_head->node->next->data < b_head->node->next->next->data)
		{
			pa(a_head, b_head);
			sb(b_head, 0);
		}
		pa(a_head, b_head);
		pa(a_head, b_head);
	}
	else
	{
		if (b_head->node->data > b_head->node->next->data && \
			b_head->node->next->data < b_head->node->next->next->data)
		{
			rb(b_head, 0);
			sb(b_head, 0);
			pa(a_head, b_head);
			rrb(b_head, 0);
		}
		else if (b_head->node->data < b_head->node->next->data && \
				b_head->node->next->data > b_head->node->next->next->data)
		{
			sb(b_head, 0);
			pa(a_head, b_head);
		}
		pa(a_head, b_head);
		pa(a_head, b_head);
	}
}

void			a_except_three(t_head *head)
{
	if (head->node->data < head->node->next->data && \
		head->node->data < head->node->next->next->data)
	{
		if (head->node->next->data > head->node->next->next->data)
		{
			ra(head, 0);
			sa(head, 0);
			rra(head, 0);
		}
		return ;
	}
	else if (head->node->data > head->node->next->data && \
			head->node->data > head->node->next->next->data)
	{
		if (head->node->next->data < head->node->next->next->data)
		{
			sa(head, 0);
			ra(head, 0);
			sa(head, 0);
			rra(head, 0);
		}
		else
		{
			sa(head, 0);
			ra(head, 0);
			sa(head, 0);
			rra(head, 0);
			sa(head, 0);
		}
		return ;
	}
	else
	{
		if (head->node->data > head->node->next->data && \
			head->node->next->data < head->node->next->next->data)
			sa(head, 0);
		else if (head->node->data < head->node->next->data && \
				head->node->next->data > head->node->next->next->data)
		{
			ra(head, 0);
			sa(head, 0);
			rra(head, 0);
			sa(head, 0);
		}
	}
}

void			b_except(t_head *a_head, t_head *b_head, int range)
{
	t_node		*curr;

	if (!b_head->node)
		return ;
	else if (range == 1)
	{
		pa(a_head, b_head);
		return ;
	}
	if (!b_head->node->next)
		return ;
	else if (range == 2)
	{
		if ((b_head->node->data < b_head->node->next->data) && range == 2)
		{
			sb(b_head, 0);
			pa(a_head, b_head);
			pa(a_head, b_head);
		}
		return ;
	}
	if (!b_head->node->next->next)
		return ;
	else if (range == 3)
		b_except_three(a_head, b_head);
}

void			a_except(t_head *head, int range)
{
	if (range == 1 || !head->node)
		return ;
	if (!head->node->next)
		return ;
	else if (range == 2 && head->node->data > head->node->next->data)
	{
		sa(head, 0);
		return ;
	}
	if (!head->node->next->next)
		return ;
	else if (range == 3)
		a_except_three(head);
}

void			b_to_a(t_head *a_head, t_head *b_head, t_init *data, int range)
{
	int			pivot[2];
	int			time_ra;
	int			time_rb;
	int			time_pa;

	time_ra = 0;
	time_rb = 0;
	time_pa = 0;
	display(*b_head, 1);
	if (range <= 3)
	{
		b_except(a_head, b_head, range);
		return ;
	}
	if ((find_pivot(b_head, pivot, range)) == 0)
		return ;
	int i = 0;
	while (i < range && b_head->node)
	{
		if (b_head->node->data < pivot[0])
		{
			rb(b_head, 0);
			time_rb++;
		}
		else
		{
			pa(a_head, b_head);
			time_pa++;
			if (a_head->node->data < pivot[1])
			{
				ra(a_head, 0);
				time_ra++;
			}
		}
		i++;
	}
	a_to_b(a_head, b_head, data, time_pa - time_ra);
	i = 0;
	while (i < time_ra && i < time_rb)
	{
		rrr(a_head, b_head);
		i++;
	}
	while (i < time_ra)
	{
		rra(a_head, 0);
		i++;
	}
	while (i < time_rb)
	{
		rrb(b_head, 0);
		i++;
	}
	a_to_b(a_head, b_head, data, time_rb);
	b_to_a(a_head, b_head, data, time_ra);
}

void			a_to_b(t_head *a_head, t_head *b_head, t_init *data, int range)
{
	int			pivot[2];
	int			time_ra;
	int			time_rb;
	int			time_pb;

	time_ra = 0;
	time_rb = 0;
	time_pb = 0;
	display(*a_head, 0);
	if (range <= 3)
	{
		a_except(a_head, range);
		return ;
	}
	if ((find_pivot(a_head, pivot, range)) == 0)
		return ;
	int i = 0;
	while (i < range && a_head->node)
	{
		if (a_head->node->data >= pivot[1])
		{
			ra(a_head, 0);
			time_ra++;
		}
		else
		{
			pb(a_head, b_head);
			time_pb++;
			if (b_head->node->data >= pivot[0])
			{
				rb(b_head, 0);
				time_rb++;
			}
		}
		i++;
	}
	i = 0;
	while (i < time_ra && i < time_rb)
	{
		rrr(a_head, b_head);
		i++;
	}
	while (i < time_ra && a_head->node)
	{
		rra(a_head, 0);
		i++;
	}
	while (i < time_rb && b_head->node)
	{
		rrb(b_head, 0);
		i++;
	}
	a_to_b(a_head, b_head, data, time_ra);
	b_to_a(a_head, b_head, data, time_rb);
	b_to_a(a_head, b_head, data, time_pb - time_rb);
}
