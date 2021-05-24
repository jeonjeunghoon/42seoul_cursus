/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 07:47:02 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/05/25 00:21:07 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdio.h>

void		ft_exit(char *msg)
{
	write(1, msg, ft_strlen(msg));
	exit(0);
}

int			is_valid_arg(int argc, char **argv)
{
	int		i;
	int		j;

	if (argc < 2)
		return (0);
	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] == '-' || argv[i][j] == '+') && j == 0)
				j++;
			if (argv[i][j] >= '0' && argv[i][j] <= '9')
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int			is_valid_num(int **num_arr, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if ((*num_arr)[i] == (*num_arr)[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

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

void		create_node_back(t_stack *lst, int *data)
{
	t_stack	*node;

	if (!lst)
		ft_exit("Error: create_node_back\n");
	if (!(node = (t_stack *)malloc(sizeof(t_stack))))
		ft_exit("Error: create_node_back\n");
	node->data = *data;
	node->next = NULL;
	lst->next = node;
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

void		ft_del_stack(t_stack *lst)
{
	lst->data = 0;
	lst->is_head = 0;
	lst->next = NULL;
	free(lst);
}

int		lstsize(t_stack *lst)
{
	int	len;

	len = 0;
	while (lst)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}

void		ft_push(t_stack **head, element data)
{
	t_stack	*node;

	if (!(node = (t_stack *)malloc(sizeof(t_stack))))
		ft_exit("Error: push\n");
	(*head)->data = data;
	(*head)->is_head = 0;
	node->next = (*head);
	node->is_head = 1;
	(*head) = node;
}

element		ft_pop(t_stack **head)
{
	t_stack	*head_temp;
	element	data;

	if ((*head)->is_head == 1 && (*head)->next == NULL)
	{
		printf("Pop Error: No Element\n");
		return (-42);
	}
	head_temp = (*head);
	(*head) = (*head)->next;
	ft_del_stack(head_temp);
	data = (*head)->data;
	(*head)->data = 0;
	(*head)->is_head = 1;
	return (data);
}

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
	element	data;

	if ((*b)->is_head == 1 && (*b)->next == NULL)
	{
		printf("No Element in A\n");
		return ;
	}
	data = ft_pop(b);
	ft_push(a, data);
}

void		pb(t_stack **a, t_stack **b)
{
	element	data;

	if ((*a)->is_head == 1 && (*a)->next == NULL)
	{
		printf("No Element in A\n");
		return ;
	}
	data = ft_pop(a);
	ft_push(b, data);
}

void		ra(t_stack **a)
{
	t_stack	*head;
	t_stack *first_head;

	head = (*a);
	if ((*a)->is_head == 1 && (*a)->next == NULL)
	{
		printf("No Element in A\n");
		return ;
	}
	first_head = (*a)->next;
	head->next = first_head->next;
	while ((*a)->next != NULL)
		(*a) = (*a)->next;
	(*a)->next = first_head;
	first_head->next = NULL;
	(*a) = head;
}

void		rb(t_stack **b)
{
	t_stack	*head;
	t_stack *first_head;

	head = (*b);
	if ((*b)->is_head == 1 && (*b)->next == NULL)
	{
		printf("No Element in A\n");
		return ;
	}
	first_head = (*b)->next;
	head->next = first_head->next;
	while ((*b)->next != NULL)
		(*b) = (*b)->next;
	(*b)->next = first_head;
	first_head->next = NULL;
	(*b) = head;
}

void		rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}

void		rra(t_stack **a, t_stack **b)
{
	
}

void		rrb(t_stack **a, t_stack **b)
{
	
}

void		rrr(t_stack **a, t_stack **b)
{
	
}

void		test(t_stack *a, t_stack *b)
{
	t_stack	*a_head;
	t_stack	*b_head;

	for (int i = 15; i > 0; i--)
		ft_push(&b, i);
	for (int i = 0; i < 1; i++)
		ss(&a, &b);
	a_head = a;
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
	b_head = b;
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
	for (;;)
	;
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
