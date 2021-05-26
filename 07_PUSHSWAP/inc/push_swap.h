/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 07:46:56 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/05/26 23:43:03 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

#include <stdio.h>

typedef	int				element;

typedef	struct			s_stack
{
	int					is_head;
	element				data;
	struct	s_stack		*next;
}						t_stack;

typedef	struct			s_init
{
	int					*num_arr;
	int					len_of_node;
	int					start;
	int					pivot;
}						t_init;

void					arg_init(int argc, char **argv, t_init **data);
void					stack_init(t_stack **a, t_stack **b, t_init *data);
size_t					ft_strlen(const char *s);
int						is_valid_num(int *num_arr, int size);
void					num_init(int argc, char **argv, t_init *data);
int						is_valid_arg(int argc, char **argv);
void					ft_exit(char *msg);
int						ft_atoi(const char *str);
void					create_node_back(t_stack *lst, int *data);
void					ft_del_stack(t_stack *lst);
void					ft_push(t_stack **head, element data);
element					ft_pop(t_stack **head);
void					sa(t_stack **a);
void					sb(t_stack **b);
void					ss(t_stack **a, t_stack **b);
void					pa(t_stack **a, t_stack **b);
void					pb(t_stack **a, t_stack **b);
void					ra(t_stack **a);
void					rb(t_stack **b);
void					rr(t_stack **a, t_stack **b);
void					rra(t_stack **a);
void					rrb(t_stack **b);
void					rrr(t_stack **a, t_stack **b);

void					ft_swap(int *a, int *b);
int						partition(int *num_arr, int left, int right);
void					quick_sort(int *num_arr, int left, int right);
void					find_pivot(t_init *data);
int						ft_partition(t_stack *a, t_stack *b, int left, int right);
void					ft_quick_sort(t_stack *a, t_stack *b, int left, int right);


#endif