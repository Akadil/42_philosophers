/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 16:38:50 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/30 19:17:05 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MONITOR_H
# define FT_MONITOR_H

# include "struct_philo.h"
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>

int		ft_is_game_finished(t_philo *philo);
void	ft_set_all_statuses_2(t_philo *philo);
int		ft_check_death(t_philo *philo, t_rules *rules, int time);

#endif
