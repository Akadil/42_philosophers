/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:29:54 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/24 17:32:27 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_routine.h"
#include <stdio.h>

// I have a problem for the last one. My second philo waiting for status changing. 
// but it is not because of line 38
void    *ft_routine(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    if (ft_get_time_beginning(philo) == -1)
        return (ft_set_status(philo, -2), NULL);
    while (1)
    {
        philo->exit_code = ft_fork(philo);
        if (philo->exit_code != 0)
            break;
        philo->exit_code = ft_eat(philo); 
        pthread_mutex_unlock(&philo->mutex);
		pthread_mutex_unlock(&philo->next->mutex);
		if (philo->exit_code != 0)
            break;
        philo->success--;
        if (philo->success == 0 && philo->status--)
            break;
        philo->exit_code = ft_sleep(philo); 
        if (philo->exit_code != 0)
            break;
        philo->round++;
    }
    return (ft_handle_error(philo), NULL);
}
