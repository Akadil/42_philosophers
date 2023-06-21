/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_rules.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 10:44:52 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/21 23:27:33 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_RULES_H
# define STRUCT_RULES_H

#include <pthread.h>

/*
    status_code:
        0   - everything is code
        -1  - someone died
        -2  - some other error
*/
typedef struct s_rules
{
    int             num_philo;
    int             time_die;
    int             time_sleep;
    int             time_eat;
    int             num_success;

    int             time_start;
    int             status_code;
    pthread_mutex_t time_of_day;
    pthread_mutex_t time_available;
    pthread_mutex_t my_turn;
}                   t_rules;

#endif
