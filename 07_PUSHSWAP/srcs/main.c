/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 07:47:02 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/07/16 12:31:26 by jeunjeon         ###   ########.fr       */
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

void	arg_init(char **argv, t_init **data)
{
	(*data) = (t_init *)malloc(sizeof(t_init));
	if (!(*data))
		ft_exit("Error\n");
	(*data)->bundle = (t_bundle_head *)malloc(sizeof(t_bundle_head));
	if (!(*data)->bundle)
		ft_exit("Error\n");
	(*data)->bundle->node = (t_bundle_node *)malloc(sizeof(t_bundle_node));
	if (!(*data)->bundle->node)
		ft_exit("Error\n");
	(*data)->bundle->node->is_top = 1;
	create_bundle(argv, *data);
	create_bundle_arr(*data, (*data)->bundle);
	if ((is_valid_arg(*data)) == 0)
		ft_exit("Error\n");
	num_init((*data));
}

void	stack_init(t_stack **stack, t_init *data)
{
	int	i;

	(*stack) = (t_stack *)malloc(sizeof(t_stack));
	if (!(*stack))
		ft_exit("Error\n");
	(*stack)->a = (t_head *)malloc(sizeof(t_head));
	if (!(*stack)->a)
		ft_exit("Error\n");
	(*stack)->a->node = (t_node *)malloc(sizeof(t_node));
	if (!(*stack)->a->node)
		ft_exit("Error\n");
	(*stack)->b = (t_head *)malloc(sizeof(t_head));
	if (!(*stack)->b)
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

int	check_stack(t_head a)
{
	int	*arr;
	int	i;

	arr = (int *)malloc(sizeof(int) * a.size);
	if (!arr)
		ft_exit("Error\n");
	reset_arr(&a, arr, a.size);
	quick_sort(arr, 0, a.size - 1);
	i = 0;
	while (i < a.size)
	{
		if (arr[i] == a.node->data)
			i++;
		else
			break ;
		a.node = a.node->next;
	}
	free(arr);
	if (i == a.size)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;
	t_init	*data;
	int		cnt;

	if (argc == 1)
		return (0);
	cnt = 0;
	arg_init(argv, &data);
	stack_init(&stack, data);
	if (check_stack(*(stack->a)))
		return (0);
	if (data->size == 3)
		except_size_three(stack->a);
	else if (data->size == 5)
		except_size_five(stack->a, stack->b);
	else
		a_to_b(stack, data, stack->a->size, &cnt);
	free_all(&stack, &data);
	return (0);
}
