/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:08:38 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/20 16:13:38 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_philo.h"

int ft_sleep(t_philo *philo)
{
    int time_available;

    time_available = ft_available_time(philo);
    if (philo->rules->time_sleep - time_available < 0)
    {
        if (usleep_alt((time_available - philo->rules->time_sleep) * 1000, philo) != 0);
            return (-2);
        ft_die();
        return (-1);
    }
    else
    {
        printf("%dms %d is sleeping\n",ft_get_time(), philo->num);
        if (usleep_alt(philo->rules->time_sleep * 1000, philo) != 0)
            return (-2);
    }
    return (0);
}