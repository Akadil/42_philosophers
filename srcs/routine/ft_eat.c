/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:02:46 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/22 00:55:18 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_eat.h"

int ft_eat(t_philo *philo)
{
    philo->status = 1;
    philo->exit_code = ft_time_available(philo); 
    if (philo->exit_code < 0)
        return (-2);
    if (philo->time_live <= 0)
        return (-1);
    philo->exit_code = ft_get_time(philo);
    if (philo->exit_code < 0)
        return (philo->exit_code);
    philo->time_curr = philo->time_curr - philo->rules->time_start;
    printf("[%7dms] %d is eating\n", philo->time_curr, philo->num);
    philo->exit_code = ft_update_philo_time(philo);
    if (philo->exit_code != 0)
        return (philo->exit_code);
    philo->time_skip = philo->rules->time_eat * 1000;
    philo->exit_code = usleep_alt(philo);
    if (philo->exit_code != 0)
        return (philo->exit_code);
    return (0);
}
