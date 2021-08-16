/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 21:45:20 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/08/16 22:06:37 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>

# define IS_ERROR -1
# define IS_DEAD -42

typedef struct s_arg
{
	int			num_of_philo;
	int			num_of_fork;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			must_eat_times;
}	t_arg;

typedef struct s_philo
{
	t_arg					*arg;
	int						order;
	int						*fork;
	pthread_t				*thread;
	const pthread_attr_t	*attr;
	void					*philo_arg;
	struct timeval			die_start;
	struct timeval			die_end;
	long long				left_time;
}	t_philo;

pthread_mutex_t	g_mutex;

/* main */

/* init */
int			arg_check(int argc, const char **argv);
int			philo_init(int argc, const char **argv, t_philo *philo);
int			arg_init(int argc, const char **argv, t_arg *arg);
int			init(int argc, const char **argv, t_philo *arg);


/* philo_func */
void		*philo_routine(void *philo);
int			philo_func(t_philo *philo);

/* philo_act */
int			sleeping(t_philo *philo, int *start, int *end);
int			switch_fork(int left_fork, int right_fork);
int			eating(t_philo *philo, int order);
int			philo_act(t_philo *philo, int order, int *start, int *end);

/* time_func */
int			is_dead(int *start, int *end, t_philo *philo);
int			get_time(int *arr, struct timeval time);
int			time_diff(int *start, int *end);


/* ft_isdigit */
int			ft_isdigit(int c);

/* ft_atoi */
void		ft_isspace(const unsigned char **pp);
long long	isminus(const unsigned char **pp);
long long	make_num(const unsigned char **pp, int sign);
void		ft_except(const char *str, long long num);
long long	ft_atoi(const char *str);

#endif
