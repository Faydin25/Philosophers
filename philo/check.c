/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faydin <faydin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 23:37:44 by faydin            #+#    #+#             */
/*   Updated: 2022/09/03 23:37:45 by faydin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	first_check(t_all *table, char **av, int ac)
{
	if (ac != 5 && ac != 6)
	{
		printf("Wrong Argument\n");
		return (1);
	}
	if (check_input(++av) || ft_process(table, av))
	{
		printf("Wrong Input\n");
		return (1);
	}
	if (init_mutexes(table))
	{
		printf("Error\n");
		return (1);
	}
	if (create_threads(table))
	{
		ft_mutex_destroy(table);
		return (1);
	}
	return (0);
}

void	ft_dead_check(t_all *table)
{
	int	i;

	i = table->number_of_philosophers;
	while (--i >= 0)
	{
		pthread_mutex_lock(&table->begin_time);
		if (ft_time() - table->philosophers[i].beginning_of_last_meal > \
		table->time_to_die)
		{
			pthread_mutex_unlock(&table->begin_time);
			table->any_dead = 1;
			printf("%lld %d is died\n", ft_time() - table->start_time, i + 1);
			break ;
		}
		pthread_mutex_unlock(&table->begin_time);
	}
}
