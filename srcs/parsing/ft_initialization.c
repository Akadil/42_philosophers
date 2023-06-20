/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialization.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:20:57 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/20 12:36:41 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_rules.h"
#include "struct_philo.h"
#include <stdio.h>

t_philo *ft_initialization(t_rules *rules)
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
            ft_error_clean_exit(philo);
        temp->num = i + 1;
        temp->round = 1;
        temp->prev = NULL;
        temp->next = NULL;
        ft_lstadd_back_alt(*philo, temp);
        i++;
    }
    i = 0;
    temp = philo;
    while (i < rules->num_philo)
    {
        pthread_mutex_init(&temp->mutex, NULL);
        temp = temp->next;
        i++;
    }
    temp = ft_lstlast_alt(philo);
    if (!temp)
    {
        temp->next = philo;
        philo->prev = temp;
    }
    return (philo);
}