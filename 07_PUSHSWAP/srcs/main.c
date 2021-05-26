/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 07:47:02 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/05/26 23:47:45 by jeunjeon         ###   ########.fr       */
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

void		stack_init(t_stack **a, t_stack **b, t_init *data)
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
	while (i < data->len_of_node)
	{
		create_node_back((*a), &(data->num_arr[i]));
		(*a) = (*a)->next;
		i++;
	}
	(*a) = head;
}

// void		test(t_stack **a, t_stack **b)
// {
// 	ft_push(a, 100);
// 	ft_push(a, 110);
// 	ft_push(a, 120);
// 	ft_push(b, 900);
// 	ft_push(b, 910);
// 	ft_push(b, 920);

// 	t_stack	*a_head;
// 	t_stack	*b_head;
// 	a_head = *a;
// 	b_head = *b;
// 	printf("######### a #########\n\n");
// 	while (1)
// 	{
// 		if (a_head->is_head)
// 			a_head = a_head->next;
// 		printf("a = %d\n", a_head->data);
// 		if (a_head->next == NULL)
// 			break ;
// 		a_head = a_head->next;
// 	}
// 	printf("\n\n######### b #########\n\n");
// 	while (1)
// 	{
// 		if (b_head->is_head)
// 			b_head = b_head->next;
// 		printf("b = %d\n", b_head->data);
// 		if (b_head->next == NULL)
// 			break ;
// 		b_head = b_head->next;
// 	}
// }

int			main(int argc, char **argv)
{
	t_stack	*a;
	t_stack *b;
	t_init	*data;

	arg_init(argc, argv, &data);
	stack_init(&a, &b, data);
	// test(&a, &b);
	find_pivot(data);
	// ft_quick_sort(&a, &b, 0, data->len_of_node - 1);
	free(a);
	free(b);
	free(data);
	return (0);
}
