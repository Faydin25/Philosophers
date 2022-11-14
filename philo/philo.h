/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faydin <faydin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 23:38:04 by faydin            #+#    #+#             */
/*   Updated: 2022/09/03 23:39:38 by faydin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

typedef struct s_philo // one for all philosophers
{
	int				id;
	int				how_many_eat;
	long long		beginning_of_last_meal;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_t		thread;
	struct s_all	*table;
}				t_philo;

typedef struct s_all // one object
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				all_ate;
	int				number_of_times_each_philosopher_must_eat;
	int				any_dead;
	int				control_six;
	long long		start_time;
	pthread_mutex_t	begin_time;
	pthread_mutex_t	many_eat;
	pthread_mutex_t	forks[200];
	t_philo			philosophers[200];
}				t_all;

//thread.c
void		ft_mutex_destroy(t_all *table);
int			ft_pthread_join(t_all *table);

//time_diff.c
long long	ft_time(void);
long long	ft_timediff(long long marked, long long now);
void		ft_sleep(long long wakeup);

//utils.c
int			ft_atoi(const char *str);
int			check_input(char **str);
int			first_check(t_all *table, char **av, int ac);

//timestamp.c
void		ft_timestamp(t_philo *philo, t_all *table, int i);

//process.c
int			ft_process(t_all *table, char **av);
int			ft_check_eat(t_all *table);
int			ft_process_control(t_all *table);
void		ft_six_arg(t_all *table);
void		philo_proc(t_philo *philo);

//utils.c
int			ft_isalpha(int c);
int			ft_isspace(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);

//check.c
void		ft_dead_check(t_all *table);
void		ft_gounlock(t_all *table);

//create.c
int			create_threads(t_all *table);
int			init_mutexes(t_all *table);
#endif
