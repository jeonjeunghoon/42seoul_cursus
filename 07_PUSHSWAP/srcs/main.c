/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 07:47:02 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/07/08 21:20:06 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	free_all(t_stack **stack, t_init **data)
{
	t_node	*temp;
	int		i;

	i = 0;
	while ((*data)->bundle_arr[i])
	{
		free((*data)->bundle_arr[i]);
		i++;
	}
	free((*data)->bundle_arr);
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

void	arg_init(int argc, char **argv, t_init **data)
{
	if (!((*data) = (t_init *)malloc(sizeof(t_init))))
		ft_exit("Error\n");
	if (!((*data)->bundle = (t_bundle_head *)malloc(sizeof(t_bundle_head))))
		ft_exit("Error\n");
	if (!((*data)->bundle->node = (t_bundle_node *)malloc(sizeof(t_bundle_node))))
		ft_exit("Error\n");
	(*data)->bundle->node->is_top = 1;
	create_bundle(argv, *data);
	create_bundle_arr(*data, (*data)->bundle);
	if ((is_valid_arg(*data)) == 0)
		ft_exit("Error\n");
	num_init((*data));
}

void	stack_init(t_stack **stack, t_init *data, int argc)
{
	int		i;

	if (!((*stack) = (t_stack *)malloc(sizeof(t_stack))))
		ft_exit("Error\n");
	if (!((*stack)->a = (t_head *)malloc(sizeof(t_head))))
		ft_exit("Error\n");
	if (!((*stack)->a->node = (t_node *)malloc(sizeof(t_node))))
		ft_exit("Error\n");
	if (!((*stack)->b = (t_head *)malloc(sizeof(t_head))))
		ft_exit("Error\n");
	(*stack)->a->size = data->size;
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

int	main(int argc, char **argv)
{
	t_stack	*stack;
	t_init	*data;

	arg_init(argc, argv, &data);
	stack_init(&stack, data, argc);
	if (data->size == 3)
		except_size_three(stack->a);
	else if (data->size == 5)
		except_size_five(stack->a, stack->b);
	else
		a_to_b(stack->a, stack->b, data, stack->a->size);
	free_all(&stack, &data);
	return (0);
}
