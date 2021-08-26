/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 21:45:20 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/08/26 17:57:29 by jeunjeon         ###   ########.fr       */
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
# define IS_FORK 0
# define IS_EATING 1
# define IS_SLEEPING 2
# define IS_THINKING 3
# define IS_DIED 4
# define IS_DONE 5

typedef struct s_arg
{
	int						num_philo;
	int						num_fork;
	long long				time_die_ms;
	long long				time_eat_ms;
	long long				time_sleep_ms;
	int						num_eat;
	int						is_done;
}	t_arg;

typedef struct s_philo
{
	pthread_t				*thread;
	int						num;
	int						left_fork;
	int						right_fork;
	long long				num_eating;
	long long				num_sleeping;
	long long				start_time_ms;
	long long				end_time_ms;
	int						flag_eat;
}	t_philo;

typedef struct s_base
{
	t_arg					*arg;
	t_philo					*philo;
	const pthread_attr_t	*attr;
	void					*routine_arg;
	int						*fork;
	pthread_mutex_t			*mutex;
	int						thread_index;
	long long				timestamp_start_ms;
	long long				timestamp_end_ms;
	long long				timestamp_diff_ms;
	int						finish_flag;
}	t_base;

/* init */
int			fork_mutex_init(t_base *base);
int			philo_init(t_base *base);
int			arg_check(int argc, const char **argv);
int			arg_init(int argc, const char **argv, t_arg *arg);
int			base_init(int argc, const char **argv, t_base **base);

/* philo_func */
void		*philo_routine(void *philo);
int			philo_func(t_base *base, t_arg *arg, t_philo *philo);

/* philo_act */
void		is_done(t_base *base, t_arg *arg, t_philo *philo);
void		is_died(t_base *base, t_arg *arg, t_philo *philo);
int			philo_act(t_base *base, t_arg *arg, t_philo *philo);

/* philo_act2 */
void		sleeping(t_base *base, t_arg *arg, t_philo *philo);
void		put_fork(t_base *base, t_arg *arg, t_philo *philo);
int			take_fork(t_base *base, t_arg *arg, t_philo *philo);
void		eating(t_base *base, t_arg *arg, t_philo *philo);
void		thinking(t_base *base, t_arg *arg, t_philo *philo);

/* time_func */
void		time_stamp(t_base *base, t_philo *philo, \
			int flag);
void		is_enough(t_base *base, t_arg *arg, t_philo *philo, \
			long long required_time_ms);
void		ft_usleep_ms(long long usleep_time);
long long	get_time_ms(void);

/* base_free */
int			fork_mutex_free(t_base *base, int num_fork);
int			philo_free(t_philo **philo, int num_philo);
int			arg_free(t_arg **arg);
int			base_free(t_base **base);

/* ft_isdigit */
int			ft_isdigit(int c);

/* ft_atoi */
void		ft_isspace(const unsigned char **pp);
long long	isminus(const unsigned char **pp);
long long	make_num(const unsigned char **pp, int sign);
void		ft_except(const char *str);
long long	ft_atoi(const char *str);

#endif
