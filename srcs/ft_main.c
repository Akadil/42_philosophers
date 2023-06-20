/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:40:06 by akadilkalim       #+#    #+#             */
/*   Updated: 2023/06/20 14:29:13 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "struct_philo.h"
#include "struct_rules.h"

int main(int argc, char **argv)
{
    t_philo   *philo;
    t_rules   rules;
    int      i;

    philo = NULL;
    ft_parsing(argc, argv, &rules);
    ft_initialization(philo, &rule);
    i = 0;
    while (i < rule.num_philo)
    {
        pthread_create(&philo->id, NULL, &ft_routine, philo);
        philo = philo->next;
        i++;
    }
    ft_close_threads();
    return (0);
}