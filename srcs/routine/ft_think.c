/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_think.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:15:02 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/20 17:45:14 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_philo.h"
#include <stdio.h>

int ft_time_available(t_philo *philo)
{
    int time_available;
    int time_passed;
    int time_curr;

    time_curr = ft_get_time();
    if (time_curr == -1)
        return (-2);
    time_passed = philo->time - time_curr;
    time_available = philo->rules->time_die - time_passed;
    return (time_available);
}

int ft_think(t_philo *philo)
{
    int time_available;
    int time_passed;
    int time_curr;

    time_curr = ft_get_time();
    if (time_curr == -1)
        return (-2);
    time_available = ft_time_available(philo);
    if (time_available == -2)
        return (-2);
    if (philo->rules->time_eat - time_available < 0)
    {
        if (usleep_alt((time_available - philo->rules->time_eat) * 1000, philo) != 0)
            return (-2);                                                    // Handle this error
        ft_die(philo);
        return (-1);
    }
    else
    {
        if (philo->status != 0)
            printf("%dms %d is thinking\n", time_curr, philo->num);
        if (usleep_alt(philo->rules->time_eat * 1000, philo) != 0)          // There can be just philos died
            return (-2);                                                    // Handle this case
    }
    return (0);
}

int usleep_alt(int ms, t_philo *philo)
{
    int num_iter;
    int remainder;
    int i;

    num_iter = ms / 100;
    remainder = ms - 100 * num_iter;
    i = 0;
    while (i < num_iter)
    {
        if (usleep(100) == -1)
            return (-2);
        if (philo->rules->status_code != 0)
            return (-1);
    }
    if (usleep(remainder) == -1)
        return (-2);
    return (0);
}
