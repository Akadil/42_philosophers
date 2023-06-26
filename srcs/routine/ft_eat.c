/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:02:46 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/27 00:41:57 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_eat.h"

int ft_eat(t_philo *philo)
{
	if (ft_check_status(philo) != 0)
		return (-1);
	if (ft_get_time(philo) != 0)
		return (-1);
	printf("[%7dms] %d is eating\n", philo->time_curr - philo->rules->time_start, philo->num);
	philo->time_eat = philo->time_curr;
	philo->time_skip = philo->rules->time_eat * 1000;
	if (usleep_alt(philo) != 0)
		return (philo->exit_code);
	return (0);
}
