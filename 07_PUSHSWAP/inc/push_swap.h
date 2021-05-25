/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 07:46:56 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/05/25 23:52:45 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

typedef	int				element;

typedef	struct			s_stack
{
	int					is_head;
	element				data;
	struct	s_stack		*next;
}						t_stack;

void					arg_init(int argc, char **argv, int **num_arr);
void					stack_init(t_stack **a, t_stack **b, int *num_arr, int len_of_node);
void					num_init(int argc, char **argv, int **num_arr);
int						is_valid_arg(int argc, char **argv);
int						is_valid_num(int **num_arr, int size);
void					ft_exit(char *msg);
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
void					rra(t_stack **a, t_stack **b);
void					rrb(t_stack **a, t_stack **b);
void					rrr(t_stack **a, t_stack **b);

#endif