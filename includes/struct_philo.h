/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_philo.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:22:57 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/24 17:11:03 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_PHILO_H
# define STRUCT_PHILO_H

#include <pthread.h>
#include <sys/time.h>
#include "struct_rules.h"

/*
    status:
        0 - is thinking
        1 - is eating
        2 - is sleeping
        3 - took one fork
*/
typedef struct s_philo
{
    pthread_t       id;
    pthread_mutex_t mutex;
    t_rules         *rules;

    int             num;
    int             time_eat;
    int             time_curr;
    int             time_live;
    int             time_skip;
    int             round;
    int             status;
    int             success;
    int             exit_code;

    int             iter;
    int             host;
    
    struct timeval  timeval;

    struct s_philo  *next;
    struct s_philo  *prev;
}                   t_philo;

#endif
