/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:29:54 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/20 16:42:28 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_philo.h"
#include <sys/time.h>
#include <stdio.h>

int ft_get_time();
int ft_fork(t_philo *philo);
int ft_eat(t_philo *philo);
int ft_sleep(t_philo *philo);

void    *ft_routine(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    philo->time = ft_get_time();
    if (philo->time == -1)
    {
        philo->rules->status_code = -2;
        return (NULL);
    }
    while (1)
    {
        if (ft_fork(philo) != 0)
            break;
        if (ft_eat(philo) != 0)
            break;
        if (ft_sleep(philo) != 0)
            break;
    }
    return (NULL);
}