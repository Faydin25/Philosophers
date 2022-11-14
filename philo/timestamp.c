/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faydin <faydin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 23:38:20 by faydin            #+#    #+#             */
/*   Updated: 2022/09/03 23:38:21 by faydin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_timestamp(t_philo *philo, t_all *table, int i)
{
	long long	time;

	time = ft_timediff(table->start_time, ft_time());
	if (i == 0)
		printf("%lld %d has taken a fork\n", time, philo->id + 1);
	else if (i == 1)
	{
		pthread_mutex_lock(&table->many_eat);
		++(philo->how_many_eat);
		pthread_mutex_unlock(&table->many_eat);
		printf("%lld %d is eating\n", time, philo->id + 1);
		pthread_mutex_lock(&table->begin_time);
		philo->beginning_of_last_meal = ft_time();
		pthread_mutex_unlock(&table->begin_time);
	}
	else if (i == 2)
		printf("%lld %d is thinking\n", time, philo->id + 1);
	else if (i == 3)
		printf("%lld %d is sleeping\n", time, philo->id + 1);
}
