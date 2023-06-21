/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:34:25 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/21 22:15:52 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TIME_H
# define FT_TIME_H

# include "struct_philo.h"

int    ft_get_time(t_philo *philo);
int    ft_get_time_beginning(t_philo *philo);
int ft_time_available(t_philo *philo);
int    ft_update_philo_time(t_philo *philo);

#endif
