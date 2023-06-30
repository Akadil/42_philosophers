/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:21:54 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/30 19:11:24 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ROUTINE_H
# define FT_ROUTINE_H

# include "struct_philo.h"
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>

int	ft_start_schedule(t_philo *philo);
void	ft_handle_error(t_philo *philo);
void	ft_set_end_status(t_philo *philo);
int		ft_fork(t_philo *philo);
int		ft_eat(t_philo *philo);
int		ft_sleep(t_philo *philo);
void	ft_handle_one_philo(t_philo *philo);

#endif
