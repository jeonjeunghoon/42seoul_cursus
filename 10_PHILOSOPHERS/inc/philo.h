/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 21:45:20 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/08/22 21:05:06 by jeunjeon         ###   ########.fr       */
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
# define IS_DEAD 1
# define IS_DONE 0

typedef struct s_arg
{
	int						num_philo;
	int						num_fork;
	long long				time_die_ms;
	long long				time_eat_ms;
	long long				time_sleep_ms;
	int						num_eat;
}	t_arg;

typedef struct s_philo
{
	pthread_t				*thread;
	int						num;
	int						left_fork;
	int						right_fork;
	long long				num_eating;
	long long				num_sleeping;
	long long				start_time;
	long long				end_time;
}	t_philo;

typedef struct s_base
{
	t_arg					*arg;
	t_philo					*philo;
	const pthread_attr_t	*attr;
	void					*routine_arg;
	int						*fork;
	int						num_thread;
}	t_base;

pthread_mutex_t	g_mutex;

/* main */

/* init */
int			arg_check(int argc, const char **argv);
int			philo_init(int argc, const char **argv, t_base *base);
int			arg_init(int argc, const char **argv, t_arg *arg);
int			base_init(int argc, const char **argv, t_base *base);


/* philo_func */
void		*philo_routine(void *philo);
int			philo_func(t_base *base, t_arg *arg, t_philo *philo);

/* philo_act */
int			sleeping(t_base base, t_arg arg, t_philo *philo);
int			switch_fork(t_base base, t_arg arg, t_philo *philo);
int			eating(t_base base, t_arg arg, t_philo *philo);
int			philo_act(t_base base, t_arg arg, t_philo *philo);

/* time_func */
void		ft_usleep_ms(long long usleep_time);
int			is_dead(t_base base, t_arg arg, t_philo *philo);
long long	get_time_ms(void);


/* ft_isdigit */
int			ft_isdigit(int c);

/* ft_atoi */
void		ft_isspace(const unsigned char **pp);
long long	isminus(const unsigned char **pp);
long long	make_num(const unsigned char **pp, int sign);
void		ft_except(const char *str, long long num);
long long	ft_atoi(const char *str);

#endif
