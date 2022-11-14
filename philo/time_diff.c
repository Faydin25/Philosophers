/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_diff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faydin <faydin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 23:38:12 by faydin            #+#    #+#             */
/*   Updated: 2022/09/03 23:38:13 by faydin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

long long	ft_timediff(long long marked, long long now)
{
	return (now - marked);
}

void	ft_sleep(long long wakeup)
{
	while (ft_time() < wakeup)
	{
		usleep(1000);
	}
}
