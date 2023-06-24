/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:27:09 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/24 17:11:45 by akalimol         ###   ########.fr       */
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
    if (rules->status_code == 0)
        return (0);
    else if (rules->status_code == -1)
        return (-1);
    return (errno);
}
