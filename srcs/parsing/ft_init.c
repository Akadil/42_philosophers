/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:20:57 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/27 19:16:50 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_init.h"
#include <string.h>

t_philo *ft_init(t_rules *rules)
{
    t_philo *philos;
    t_philo *philo;
    int     i;

    philos = NULL;
    i = 0;
    while (i < rules->num_philo)
    {
        philo = (t_philo *)malloc(sizeof(t_philo));
        if (!philo)
            return (ft_error_clean_exit(philos), NULL);
        memset(philo, 0, sizeof(t_philo));
        if (pthread_mutex_init(&philo->fork, NULL) != 0)
            return (free (philo), ft_error_clean_exit(philos), NULL);
        if (pthread_mutex_init(&philo->exit, NULL) != 0)
            return (free (philo), ft_error_clean_exit(philos), NULL);     // this one is wrong cleaning
        if (pthread_mutex_init(&philo->meal, NULL) != 0)
            return (free (philo), ft_error_clean_exit(philos), NULL);
        philo->num = i + 1;
        philo->success = rules->num_success;
        philo->rules = rules;
        philo->time_eat = rules->time_start;
        ft_lstadd_back_alt(&philos, philo);
        i++;
    }
    ft_connect_first_last(philos);
    return (philos);
}

void    ft_connect_first_last(t_philo *philo)
{
    t_philo *last;

    if (!philo)
        return ;
    last = ft_lstlast_alt(philo);
    philo->prev = last;
    last->next = philo;
}
