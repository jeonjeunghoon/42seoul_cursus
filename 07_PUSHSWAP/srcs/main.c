/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 07:47:02 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/07/06 17:57:15 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void		free_all(t_stack **stack, t_init **data)
{
	t_node	*temp;

	free((*data)->num_arr);
	free(*data);
	while ((*stack)->a->node != NULL)
	{
		temp = (*stack)->a->node;
		(*stack)->a->node = (*stack)->a->node->next;
		free(temp);
	}
	free((*stack)->a);
	free((*stack)->b);
	free(*stack);
}

void		arg_init(int argc, char **argv, t_init **data)
{
	(*data) = (t_init *)malloc(sizeof(t_init));
	if ((is_valid_arg(argc, argv) == 0) || argc < 2)
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
	(*stack)->b->node = NULL;
	(*stack)->b->size = 0;
	i = 1;
	while (i < (*stack)->a->size)
	{
		create_node_back((*stack)->a->node, data->num_arr[i]);
		i++;
	}
}

void		display(t_head head, int alpha)
{
	if (head.size == 0)
		return ;
	printf("\n----------stack----------\n");
	while (1)
	{
		printf("%d\n", head.node->data);
		if (head.node->next == NULL)
		{
			printf("----------stack----------\n");
			if (alpha == 0)
				printf("A SIZE = %d\n", head.size);
			else
				printf("B SIZE = %d\n", head.size);
			return ;
		}
		head.node = head.node->next;
	}
}

int			main(int argc, char **argv)
{
	t_stack	*stack;
	t_init	*data;

	arg_init(argc, argv, &data);
	stack_init(&stack, data, argc);
	a_to_b(stack->a, stack->b, data, stack->a->size);
	display(*(stack->a), 0);
	display(*(stack->b), 1);
	printf("TIMES = %03d\n\n", times);
	free_all(&stack, &data);
	// for(;;)
	// ;
	return (0);
}
