/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:29:54 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/27 00:45:58 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_routine.h"

void    ft_unlock_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->next->fork);
    pthread_mutex_unlock(&philo->fork);
}

void    *ft_routine(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    if (ft_start_schedule(philo) != 0)
        return (ft_handle_error(philo), NULL);
    while (1)
    {
        if (ft_fork(philo) != 0)
            break ;
        if (ft_eat(philo) != 0)
        {
            ft_unlock_forks(philo);
            break ;    
        }
        ft_unlock_forks(philo);
        if (--philo->success == 0)
            break ; 
        if (ft_sleep(philo) != 0)
            break ;
    }
    if (philo->exit_code == -1 || philo->exit_code == -2)
        ft_handle_error(philo);
    return (NULL);
}
