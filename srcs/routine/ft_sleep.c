/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:08:38 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/22 00:48:51 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_sleep.h"
#include "struct_philo.h"


int ft_sleep(t_philo *philo)
{
    philo->status = 2;
    philo->exit_code = ft_time_available(philo);
    if (philo->exit_code < 0)
        return (philo->exit_code);
    if (philo->time_live - philo->rules->time_sleep < 0)
    {
        philo->time_skip = philo->time_live * 1000;
        if (usleep_alt(philo) != 0)
            return (-2);
        return (-1);
    }
    else
    {
        philo->exit_code = ft_get_time(philo);
        if (philo->exit_code != 0)
            return (philo->exit_code);
        philo->time_curr = philo->time_curr - philo->rules->time_start;
        printf("[%7dms] %d is sleeping\n", philo->time_curr, philo->num);
        philo->time_skip = philo->rules->time_sleep * 1000;
        if (usleep_alt(philo) != 0)
            return (-2);
    }
    return (0);
}
