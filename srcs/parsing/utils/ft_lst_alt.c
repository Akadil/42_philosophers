/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_alt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:17:42 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/21 15:18:15 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_philo.h"
#include <stdio.h>

t_philo *ft_lstlast_alt(t_philo *philo)
{
    if (!philo)
        return (NULL);
    while (philo->next)
        philo = philo->next;
    return (philo);
}

void    ft_lstadd_back_alt(t_philo **head, t_philo *philo)
{
    t_philo *last;

    last = ft_lstlast_alt(*head);
    if (!last)
        *head = philo;
    else
    {
        last->next = philo;
        philo->prev = last;
    }
}
