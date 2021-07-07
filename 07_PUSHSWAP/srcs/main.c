/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 07:47:02 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/07/07 18:23:32 by jeunjeon         ###   ########.fr       */
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

int			check_split(char *argv)
{
	int		i;
	int		is_first;
	int		is_empty;

	i = 0;
	is_empty = 1;
	while (argv[i])
	{
		is_first = 1;
		if ((argv[i] == '-' || argv[i] == '+') && is_first == 1)
		{
			i++;
			is_first = 0;
		}
		else if (argv[i] >= '0' && argv[i] <= '9')
		{
			is_empty = 0;
			i++;
		}
		else if (argv[i] == ' ')
		{
			i++;
			is_first = 1;
		}
		else
			return (0);
	}
	if (is_empty == 1)
		return (0);
	return (1);
}

int			is_valid_arg(char **argv)
{
	int		i;
	int		j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			// 작은따옴표 어케 처리할까???
			// 빈문자열도 처리해야 하나???
			if ((argv[i][j] == '-' || argv[i][j] == '+') && j == 0)
				j++;
			else if (argv[i][j] >= '0' && argv[i][j] <= '9' && argv[i][j])
				j++;
			else if (argv[i][j] == ' ')
			{
				if (check_split(argv[i]))
					break ;
				else
					return (0);
			}
			else
				return (0);
		}
		i++;
	}
	return (1);
}

void		arg_init(int argc, char **argv, t_init **data)
{
	if (argc < 2)
		ft_exit("Error: arg_init\n");
	if ((is_valid_arg(argv) == 0))
		ft_exit("Error: arg_init\n");
	(*data) = (t_init *)malloc(sizeof(t_init));
	if ((create_num(argc, argv, (*data)) == 0) || argc < 2)
		ft_exit("Error: arg_init\n");
	num_init((*data));
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
