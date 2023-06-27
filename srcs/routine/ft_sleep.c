/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:08:38 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/27 15:24:46 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_sleep.h"
#include "struct_philo.h"
#include <unistd.h>

int ft_gettime_sleep(t_philo *philo)
{
	// printf("%d: %d\n", philo->num, philo->time_curr);
	// printf("%d: %d\n", philo->num, philo->rules->time_eat * 1000);
	// printf("%d: %d\n", philo->num, philo->rules->time_start);
    return (philo->time_curr - philo->rules->time_start);
}

int ft_gettime_think(t_philo *philo)
{
    return (philo->time_curr - philo->rules->time_start);
}

int ft_sleep(t_philo *philo)
{
	if (ft_get_time(philo) != 0)
		return (-1);
	if (ft_check_status(philo) != 0)
		return (-1);
	printf("[%7dms] %d is sleeping\n", ft_gettime_sleep(philo), philo->num);
	philo->time_skip = philo->rules->time_sleep * 1000;
	if (usleep(philo->time_skip) != 0)
		return (-1);
	if (ft_get_time(philo) != 0)
		return (-1);
	if (ft_check_status(philo) != 0)
		return (-1);
	printf("[%7dms] %d is thinking\n", ft_gettime_think(philo), philo->num);
	return (0);
}
