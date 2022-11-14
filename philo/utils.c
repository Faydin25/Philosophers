/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faydin <faydin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 23:38:22 by faydin            #+#    #+#             */
/*   Updated: 2022/09/03 23:44:30 by faydin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	max_value(long long n)
{
	if (n > 2147483647 || n < -2147483648)
		return (0);
	else
		return (n);
}

int	ft_atoi(const char *str)
{
	long		i;
	long long	result;

	i = 0;
	result = 0;
	while (str[i] == ' ' || (str[i] <= 13 && str[i] >= 9))
		i++;
	if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + str[i++] - '0';
		if (result > 2147483647)
			return (max_value(result));
	}
	return (result);
}

int	check_input(char **str)
{
	char	*ptr;
	short	allspace;

	ptr = *str;
	while (ptr)
	{
		allspace = 1;
		while (*ptr)
		{
			if (ft_isdigit(*ptr))
			{
				ptr += 1;
				allspace = 0;
			}
			else if ((*ptr == '+') && ft_isdigit(*(ptr + 1)) \
			&& (!ft_isalnum(*(ptr - 1)) || ft_isspace(*ptr)))
				ptr += 1;
			else
				return (1);
		}
		if (allspace)
			return (1);
		ptr = *(++str);
	}
	return (0);
}
