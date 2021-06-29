/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 07:46:56 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/06/29 17:52:40 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

#include <stdio.h>

typedef	struct			s_node
{
	int					data;
	struct	s_node		*prev;
	struct	s_node		*next;
}						t_node;

typedef	struct			s_head
{
	int					size;
	t_node				*node;
}						t_head;

typedef	struct			s_stack
{
	t_head				*a;
	t_head				*b;
}						t_stack;

typedef	struct			s_init
{
	int					*num_arr;
	int					start;
	int					pivot;
}						t_init;

void					arg_init(int argc, char **argv, t_init **data);
void					stack_init(t_stack **stack, t_init *data, int argc);

size_t					ft_strlen(const char *s);
int						is_valid_num(int *num_arr, int size);
void					num_init(int argc, char **argv, t_init *data);
int						is_valid_arg(int argc, char **argv);

void					ft_exit(char *msg);
int		 				ft_atoi(const char *str);
void					create_node_back(t_node *node, int data);
void					ft_del_node(t_node *node);
void					ft_push(t_head *head, int data);
int						ft_pop(t_head *head);

void					sa(t_head *head);
void					sb(t_head *head);
void					ss(t_head *a_head, t_head *b_head);
void					pa(t_head *a_head, t_head *b_head);
void					pb(t_head *a_head, t_head *b_head);
void					ra(t_head *a_head);
void					rb(t_head *b_head);
void					rr(t_head *a_head, t_head *b_head);
void					rra(t_head *a_head);
void					rrb(t_head *b_head);
void					rrr(t_head *a_head, t_head *b_head);

void					ft_swap(int *a, int *b);
int						partition(int *num_arr, int left, int right);
void					quick_sort(int *num_arr, int left, int right);
void					find_pivot(t_init *data, int size);

int						ft_partition(t_head *a_head, t_head *b_head, int left, int right);
void					push_swap(t_head *a_head, t_head *b_head, int left, int right);

#endif