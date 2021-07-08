/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 07:46:56 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/07/08 21:08:53 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef	struct				s_node
{
	int						data;
	struct	s_node			*prev;
	struct	s_node			*next;
}							t_node;

typedef	struct				s_head
{
	int						size;
	t_node					*node;
}							t_head;

typedef	struct				s_stack
{
	t_head					*a;
	t_head					*b;
}							t_stack;

typedef	struct				s_bundle_node
{
	int						is_top;
	char					*num_ptr;
	struct	s_bundle_node	*next;
}							t_bundle_node;

typedef		struct			s_bundle_head
{
	t_bundle_node			*node;
}							t_bundle_head;

typedef	struct				s_init
{
	t_bundle_head			*bundle;
	char					**bundle_arr;
	int						size;
	int						*num_arr;
	int						large_pivot;
	int						small_pivot;
}							t_init;

void						free_all(t_stack **stack, t_init **data);
void						arg_init(int argc, char **argv, t_init **data);
void						stack_init(t_stack **stack, t_init *data, int argc);

void						except_size_three(t_head *head);
int							find_mid_pivot(t_head head);
void						except_size_five(t_head *a, t_head *b);

char						*ft_strdup(const char *s1);

size_t						col_size(char const *s, char c);
size_t						row_size(char const *s, char c);
void						ft_free(char **pp);
char						**make_split(char const *s, char **pp, char c);
char						**ft_split(char const *s, char c);

void						ft_isspace(const unsigned char **pp);
long long					isminus(const unsigned char **pp);
long long					make_num(const unsigned char **pp, int sign);
void						ft_except(const char *str, long long num);
int		 					ft_atoi(const char *str);

void						get_size(t_init *data, t_bundle_head head);
void						create_bundle_arr(t_init *data, t_bundle_head *head);
void						add_bundle(char *s, t_bundle_node *node);
int							is_split(char *s);
void						create_bundle(char **argv, t_init *data);

size_t						ft_strlen(const char *s);
int							is_valid_num(int *num_arr, int size);
void						num_init(t_init *data);
int							is_valid_arg(t_init *data);

void						ft_exit(char *msg);
void						ft_del_node(t_node *node);
void						ft_push(t_head *head, int data);
int							ft_pop(t_head *head);
void						create_node_back(t_node *node, int data);

void						sa(t_head *head, int is_ss);
void						sb(t_head *head, int is_ss);
void						ss(t_head *a_head, t_head *b_head);
void						pa(t_head *a_head, t_head *b_head);
void						pb(t_head *a_head, t_head *b_head);
void						ra(t_head *a_head, int is_rr);
void						rb(t_head *b_head, int is_rr);
void						rr(t_head *a_head, t_head *b_head);
void						rra(t_head *a_head, int is_rrr);
void						rrb(t_head *b_head, int is_rrr);
void						rrr(t_head *a_head, t_head *b_head);

void						ft_swap(int *a, int *b);
int							partition(int *num_arr, int left, int right);
void						quick_sort(int *num_arr, int left, int right);
void						reset_arr(t_head *head, int *arr, int range);
int							find_pivot(t_head *head, int *pivot, int range);

void						b_except_three(t_head *a_head, t_head *b_head);
void						a_except_three(t_head *head);
void						b_except(t_head *a_head, t_head *b_head, int modify_range);
void						a_except(t_head *head, int modify_range);
void						b_to_a(t_head *a_head, t_head *b_head, t_init *data, int range);
void						a_to_b(t_head *a_head, t_head *b_head, t_init *data, int range);

#endif
