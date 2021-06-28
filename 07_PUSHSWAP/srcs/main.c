/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 07:47:02 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/06/28 17:00:02 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void		arg_init(int argc, char **argv, t_init **data)
{
	(*data) = (t_init *)malloc(sizeof(t_init));
	if ((is_valid_arg(argc, argv) == 0))
		ft_exit("Error: arg_init\n");
	num_init(argc, argv, (*data));
	(*data)->len_of_node = argc - 1;
}

void		stack_init(t_stack **stack, t_init *data)
{
	int		i;

	if (!((*stack) = (t_stack *)malloc(sizeof(t_stack))))
		ft_exit("Error: stack_init1\n");
	if (!((*a) = (t_stack *)malloc(sizeof(t_stack))))
		ft_exit("Error: stack_init1\n");
	(*a)->is_head = 1;
	(*a)->next = NULL;
	if (!((*b) = (t_stack *)malloc(sizeof(t_stack))))
		ft_exit("Error: stack_init2\n");
	(*b)->is_head = 1;
	(*b)->next = NULL;
	i = 0;
	head = (*a);
	while (i < data->len_of_node)
	{
		create_node_back((*a), &(data->num_arr[i]));
		(*a) = (*a)->next;
		i++;
	}
	(*a) = head;
}

void		print_stack(t_node *node)
{
	while (1)
	{
		if (node->next == NULL)
		{
			printf("%d\n", node->data);
			printf("___\n");
			return ;
		}
		printf("%d\n", node->data);
		node = node->next;
	}
}

int			main(int argc, char **argv)
{
	t_stack	*stack;
	t_init	*data;

	arg_init(argc, argv, &data);
	stack_init(&stack, data);
	print_stack(stack->a->node);
	find_pivot(data);
	// ft_quick_sort(&a, &b, 0, data->len_of_node - 1);
	return (0);
}
