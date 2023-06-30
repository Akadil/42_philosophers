/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_philo.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:22:57 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/30 16:43:56 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_PHILO_H
# define STRUCT_PHILO_H

# include "struct_rules.h"
# include <pthread.h>
# include <sys/time.h>

/*
    status:
        0 - is thinking
        1 - is eating
        2 - is sleeping
        3 - took one fork
*/
typedef struct s_philo
{
	pthread_t		id;
	pthread_mutex_t	fork;
	pthread_mutex_t	exit;
	pthread_mutex_t	meal;
	t_rules			*rules;

	int				num;
	int				num_meal;
	int				time_eat;
	int				time_curr;
	int				exit_code;

	struct timeval	tv;
	struct s_philo	*next;
	struct s_philo	*prev;
}					t_philo;

#endif
