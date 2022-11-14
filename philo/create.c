/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faydin <faydin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 23:37:56 by faydin            #+#    #+#             */
/*   Updated: 2022/09/03 23:37:57 by faydin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_proc(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	ft_timestamp(philo, philo->table, 0);
	pthread_mutex_lock(philo->right_fork);
	ft_timestamp(philo, philo->table, 0);
	ft_timestamp(philo, philo->table, 1);
	ft_sleep(philo->beginning_of_last_meal + philo->table->time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	ft_timestamp(philo, philo->table, 3);
	ft_sleep(philo->beginning_of_last_meal + \
	philo->table->time_to_eat + philo->table->time_to_sleep);
	ft_timestamp(philo, philo->table, 2);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->table->number_of_philosophers % 2 && \
	philo->id == philo->table->number_of_philosophers - 1)
		usleep(30);
	if (!(philo->id % 2))
	{
		usleep(100);
	}
	while (!(philo->table->any_dead))
	{
		if (philo->table->control_six == 0)
			if (ft_check_eat(philo->table) == 0)
				break ;
		philo_proc(philo);
	}
	ft_gounlock(philo->table);
	return (NULL);
}

void	ft_create_threads_sup(t_all *table)
{
	int	i;

	i = -1;
	while (++i < table->number_of_philosophers)
	{
		table->philosophers[i].id = i;
		table->philosophers[i].left_fork = &(table->forks[i]);
		table->philosophers[i].right_fork = &(table->forks[(i + 1) % \
		table->number_of_philosophers]);
		table->philosophers[i].table = table;
	}
}

int	create_threads(t_all *table)
{
	int	i;

	i = -1;
	ft_create_threads_sup(table);
	table->start_time = ft_time();
	while (++i < table->number_of_philosophers)
	{
		table->philosophers[i].beginning_of_last_meal = ft_time();
		if (pthread_create(&(table->philosophers[i].thread), \
		NULL, &routine, &(table->philosophers[i])))
			return (1);
	}
	return (0);
}
