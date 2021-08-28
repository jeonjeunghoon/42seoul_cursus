/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 21:45:20 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/08/28 01:47:52 by jeunjeon         ###   ########.fr       */
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
# define IS_DIE -1
# define IS_DONE 5

typedef struct s_arg
{
	int						num_philo;
	int						num_fork;
	long long				die_ms;
	long long				eat_ms;
	long long				sleep_ms;
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
	int						can_taking;
	int						can_eating;
	int						can_putting;
	int						can_sleeping;
	int						can_thinking;
	long long				start_ms;
	long long				end_ms;
	long long				diff_ms;
	int						flag_eat;
}	t_philo;

typedef struct s_base
{
	t_arg					*arg;
	t_philo					*philo;
	const pthread_attr_t	*attr;
	void					*routine_arg;
	pthread_mutex_t			*fork;
	pthread_mutex_t			ft_mutex;
	int						*philo_fork;
	int						thread_index;
	long long				timestamp_start_ms;
	long long				timestamp_end_ms;
	long long				timestamp_diff_ms;
	int						is_die;
}	t_base;

/* main */
int			except(int argc);

/* init */
int			fork_mutex_init(t_base *base);
int			philo_init(t_base *base);
int			arg_check(int argc, const char **argv);
int			arg_init(int argc, const char **argv, t_base *base);
int			base_init(int argc, const char **argv, t_base **base);

/* philo_func */
void		wait_thread(t_base *base, t_arg *arg, t_philo *philo);
void		*philo_routine(void *philo);
int			philo_func(t_base *base, t_arg *arg, t_philo *philo);

/* philo_act */
int			thinking(t_base *base, t_arg *arg, t_philo *philo);
int			sleeping(t_base *base, t_arg *arg, t_philo *philo);
int			put_fork(t_base *base, t_arg *arg, t_philo *philo);
int			eating(t_base *base, t_arg *arg, t_philo *philo);
int			take_fork(t_base *base, t_arg *arg, t_philo *philo);

/* philo_act2 */
int			is_done(t_base *base, t_arg *arg, t_philo *philo);
int			is_die(t_base *base, t_arg *arg, t_philo *philo);
int			act_except(t_base *base, t_arg *arg, t_philo *philo);

/* time_func */
void		time_stamp(t_base *base, t_philo *philo, int flag);
int			is_enough(t_base *base, t_arg *arg, t_philo *philo, \
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
