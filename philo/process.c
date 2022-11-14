/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faydin <faydin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 23:38:07 by faydin            #+#    #+#             */
/*   Updated: 2022/09/03 23:38:08 by faydin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_process_control(t_all *table)
{
	if (table->number_of_philosophers <= 0)
		return (1);
	if (table->time_to_die <= 0)
		return (1);
	if (table->time_to_eat <= 0)
		return (1);
	if (table->time_to_sleep <= 0)
		return (1);
	return (0);
}

int	ft_process(t_all *table, char **av)
{
	int	i;

	table->number_of_philosophers = ft_atoi(av[0]);
	table->time_to_die = ft_atoi(av[1]);
	table->time_to_eat = ft_atoi(av[2]);
	table->time_to_sleep = ft_atoi(av[3]);
	if (av[4])
	{
		ft_six_arg(table);
		table->control_six = 0;
		table->number_of_times_each_philosopher_must_eat = ft_atoi(av[4]);
	}
	else
		table->control_six = 1;
	i = ft_process_control(table);
	if (i)
		return (1);
	return (0);
}

void	ft_six_arg(t_all *table)
{
	int	i;

	i = table->number_of_philosophers;
	while (--i >= 0)
		table->philosophers[i].how_many_eat = 0;
}

int	ft_check_eat(t_all *table)
{
	int	i;
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (1)
	{
		i = table->number_of_philosophers;
		k = 0;
		while (--i >= 0)
		{
			pthread_mutex_lock(&table->many_eat);
			if (table->philosophers[i].how_many_eat >= \
			table->number_of_times_each_philosopher_must_eat)
				k++;
			pthread_mutex_unlock(&table->many_eat);
		}
		if (k == table->number_of_philosophers)
			break ;
		else
			return (1);
	}
	return (0);
}
