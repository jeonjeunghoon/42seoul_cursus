/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 07:47:02 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/05/25 23:48:53 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdio.h>

void		num_init(int argc, char **argv, int **num_arr)
{
	int		i;

	*num_arr = (int *)malloc(sizeof(int) * (argc - 1));
	i = 1;
	while (argv[i])
	{
		(*num_arr)[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	if ((is_valid_num(num_arr, argc - 1) == 0))
		ft_exit("Error: num_init");
}

void		arg_init(int argc, char **argv, int **num_arr)
{
	if ((is_valid_arg(argc, argv) == 0))
		ft_exit("Error: arg_init");
	num_init(argc, argv, num_arr);
}

void		stack_init(t_stack **a, t_stack **b, int *num_arr, int len_of_node)
{
	int		i;
	t_stack	*head;

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
	while (i < len_of_node)
	{
		create_node_back((*a), &(num_arr[i]));
		(*a) = (*a)->next;
		i++;
	}
	(*a) = head;
}

void		test(t_stack *a, t_stack *b)
{
	t_stack	*a_head;
	t_stack	*b_head;

	for (int i = 10; i > 0; i--)
		ft_push(&b, i);
	for (int i = 0; i < 3; i++)
		rrr(&a, &b);
	a_head = a;
	b_head = b;
	printf("######### a #########\n\n");
	while (1)
	{
		if (a_head->is_head)
			a_head = a->next;
		printf("a = %d\n", a_head->data);
		if (a_head->next == NULL)
			break ;
		a_head = a_head->next;
	}
	printf("\n\n######### b #########\n\n");
	while (1)
	{
		if (b_head->is_head)
			b_head = b_head->next;
		printf("b = %d\n", b_head->data);
		if (b_head->next == NULL)
			break ;
		b_head = b_head->next;
	}
}

int			main(int argc, char **argv)
{
	t_stack	*a;
	t_stack *b;
	int		*num_arr;

	arg_init(argc, argv, &num_arr);
	stack_init(&a, &b, num_arr, argc - 1);
	test(a, b);
	return (0);
}
