/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_philo.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:22:57 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/20 15:26:54 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_PHILO_H
# define STRUCT_PHILO_H

#include <pthread.h>
#include "struct_rules.h"

typedef struct s_philo
{
    pthread_t       id;
    pthread_mutex_t mutex;
    int             num;
    long            time;
    int             round;
    int             status;
    
    t_rules         *rules;
    struct s_philo  *next;
    struct s_philo  *prev;
}   t_philo;

#endif
