/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faydin <faydin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 23:38:09 by faydin            #+#    #+#             */
/*   Updated: 2022/09/03 23:38:10 by faydin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_mutex_destroy(t_all *table)
{
	int	i;

	i = 0;
	while (i < table->number_of_philosophers)
		pthread_mutex_destroy(&table->forks[i--]);
}

int	ft_pthread_join(t_all *table)
{
	int	i;

	i = 0;
	while (i < table->number_of_philosophers)
	{
		if (pthread_detach(table->philosophers[i++].thread))
			return (1);
	}
	return (0);
}
