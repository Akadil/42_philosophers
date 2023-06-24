/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_think.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:15:02 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/24 17:48:55 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_think.h"
#include <stdio.h>

/*
    In ft_fork(),
	I used it to think eating time. Maybe there is a better configurations
    for that
*/
int	ft_think(t_philo *philo)
{
	philo->exit_code = ft_get_time(philo);
	if (philo->exit_code != 0)
		return (philo->exit_code);
	philo->exit_code = ft_time_available(philo);
	if (philo->exit_code != 0)
		return (philo->exit_code);
	if (philo->time_live < 0)
		return (-1);
	else
	{
		if (philo->status != 0)
			printf("[%7dms] %d is thinking\n", philo->time_curr - philo->rules->time_start, philo->num);
		philo->status = 0;
		philo->time_skip = 10;
		philo->exit_code = usleep_alt(philo);
		if (philo->exit_code != 0)     // There can be just philos died
			return (philo->exit_code); // Handle this case
	}
	return (0);
}

/*
int	ft_think(t_philo *philo)
{
	philo->exit_code = ft_get_time(philo);
	if (philo->exit_code != 0)
		return (philo->exit_code);
	philo->exit_code = ft_time_available(philo);
	if (philo->exit_code != 0)
		return (philo->exit_code);
	if (philo->time_live - philo->rules->time_eat < 0)
	{
		printf("%d\n", philo->num);
		philo->time_skip = philo->time_live * 1000;
		philo->exit_code = usleep_alt(philo);
		if (philo->exit_code != 0)
			return (philo->exit_code); // Handle this error
		return (-1);
	}
	else
	{
		if (philo->status != 0)
			printf("[%7dms] %d is thinking\n", philo->time_curr - philo->rules->time_start, philo->num);
		philo->status = 0;
		// philo->time_skip = philo->rules->time_eat * 1000;
		philo->time_skip = 1000;
		philo->exit_code = usleep_alt(philo);
		if (philo->exit_code != 0)     // There can be just philos died
			return (philo->exit_code); // Handle this case
	}
	return (0);
}
*/
