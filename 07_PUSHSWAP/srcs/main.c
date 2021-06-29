/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 07:47:02 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/06/29 17:53:37 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void		arg_init(int argc, char **argv, t_init **data)
{
	(*data) = (t_init *)malloc(sizeof(t_init));
	if ((is_valid_arg(argc, argv) == 0))
		ft_exit("Error: arg_init\n");
	num_init(argc, argv, (*data));
}

void		stack_init(t_stack **stack, t_init *data, int argc)
{
	int		i;

	if (!((*stack) = (t_stack *)malloc(sizeof(t_stack))))
		ft_exit("Error: stack_init1\n");
	if (!((*stack)->a = (t_head *)malloc(sizeof(t_head))))
		ft_exit("Error: stack_init1\n");
	if (!((*stack)->a->node = (t_node *)malloc(sizeof(t_node))))
		ft_exit("Error: stack_init1\n");
	if (!((*stack)->b = (t_head *)malloc(sizeof(t_head))))
		ft_exit("Error: stack_init1\n");
	(*stack)->a->size = argc - 1;
	(*stack)->a->node->data = data->num_arr[0];
	(*stack)->a->node->next = NULL;
	i = 1;
	while (i < (*stack)->a->size)
	{
		create_node_back((*stack)->a->node, data->num_arr[i]);
		i++;
	}
}

void		display(t_head head, int alpha)
{
	if (!head.node)
		return ;
	while (1)
	{
		if (head.node->next == NULL)
		{
			printf("%d\n", head.node->data);
			printf("___\n");
			if (alpha == 0)
				printf("A\n\n");
			else
				printf("B\n\n");
			return ;
		}
		printf("%d\n", head.node->data);
		head.node = head.node->next;
	}
}

int			main(int argc, char **argv)
{
	t_stack	*stack;
	t_init	*data;

	arg_init(argc, argv, &data);
	stack_init(&stack, data, argc);
	find_pivot(data, stack->a->size);
	printf("%d\n", data->pivot);
	printf("%d\n", data->start);
	// push_swap(stack->a, stack->b, 0, data->len_of_node - 1);
	// display(*(stack->a), 0);
	// display(*(stack->b), 1);
	return (0);
}
