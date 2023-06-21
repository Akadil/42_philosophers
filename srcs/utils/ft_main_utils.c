/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:27:09 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/21 23:28:49 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "struct_philo.h"
#include "ft_clean.h"
#include <errno.h>
#include <pthread.h>

int    ft_close_threads(t_philo *philo, t_rules *rules, int pos)
{
    t_philo *temp;
    int     i;

    i = 0;
    temp = philo;
    while (i < rules->num_philo)
    {
        if (pthread_join(temp->id, NULL) != 0)
            return (-1);
        temp = temp->next;
        i++;
    }
    temp = philo->prev;
    if (temp)
        temp->next = NULL;
    philo->prev = NULL;
    temp = philo;
    ft_clean_alt(philo, pos);
    pthread_mutex_destroy(&rules->time_of_day);
    pthread_mutex_destroy(&rules->time_available);
    pthread_mutex_destroy(&rules->my_turn);
    if (rules->status_code == 0)
        return (0);
    else if (rules->status_code == -1)
        return (-1);
    return (errno);
}
