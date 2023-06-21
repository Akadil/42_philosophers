/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:20:57 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/21 23:28:00 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_init.h"

t_philo *ft_init(t_rules *rules)
{
    t_philo *philo;
    t_philo *temp;
    int     i;

    philo = NULL;
    i = 0;
    while (i < rules->num_philo)
    {
        temp = (t_philo *)malloc(sizeof(t_philo));
        if (!temp)
            return (ft_error_clean_exit(philo), NULL);
        if (pthread_mutex_init(&temp->mutex, NULL) != 0)
            return (free (temp), ft_error_clean_exit(philo), NULL);
        temp->num = i + 1;
        temp->round = 1;
        temp->prev = NULL;
        temp->next = NULL;
        temp->status = 0;
        temp->success = rules->num_success;
        temp->rules = rules;
        ft_lstadd_back_alt(&philo, temp);
        i++;
    }
    ft_connect_first_last(philo);
    return (philo);
}

void    ft_connect_first_last(t_philo *philo)
{
    t_philo *last;

    pthread_mutex_init(&philo->rules->time_of_day, NULL);
    pthread_mutex_init(&philo->rules->time_available, NULL);
    pthread_mutex_init(&philo->rules->my_turn, NULL);
    if (!philo)
        return ;
    last = ft_lstlast_alt(philo);
    philo->prev = last;
    last->next = philo;
}
