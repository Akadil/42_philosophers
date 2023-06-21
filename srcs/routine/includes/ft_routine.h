/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:21:54 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/21 19:07:15 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ROUTINE_H
# define FT_ROUTINE_H

# include "ft_time.h"
# include "struct_philo.h"
# include <sys/time.h>
# include <stdio.h>
# include <pthread.h>

void    ft_handle_error(t_philo *philo);
void    ft_set_status(t_philo *philo, int exit_code);
int ft_fork(t_philo *philo);
int ft_eat(t_philo *philo);
int ft_sleep(t_philo *philo);

#endif
