/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faydin <faydin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 23:38:00 by faydin            #+#    #+#             */
/*   Updated: 2022/09/03 23:39:25 by faydin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_gounlock(t_all *table)
{
	int	i;

	i = table->number_of_philosophers;
	while (--i >= 0)
	{
		pthread_mutex_unlock(&table->forks[i]);
	}
}

int	init_mutexes(t_all *table)
{
	int	i;

	i = 0;
	while (i < table->number_of_philosophers)
	{
		if (pthread_mutex_init((table->forks) + i++, NULL))
		{
			while (i)
				pthread_mutex_destroy(table->forks + --i);
			return (1);
		}
	}
	pthread_mutex_init(&table->begin_time, NULL);
	pthread_mutex_init(&table->many_eat, NULL);
	return (0);
}

int	main(int ac, char **av)
{
	t_all			table;
	struct timeval	time;

	gettimeofday(&time, NULL);
	first_check(&table, av, ac);
	while (1)
	{
		ft_dead_check(&table);
		if (table.any_dead == 1 || \
		(ft_check_eat(&table) == 0 && table.control_six == 0))
			break ;
	}
	if (ft_pthread_join(&table))
	{
		ft_mutex_destroy(&table);
		return (1);
	}
	return (0);
}
