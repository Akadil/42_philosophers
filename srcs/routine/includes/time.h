/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:34:25 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/30 15:40:25 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME_H
# define TIME_H

# include "struct_philo.h"

int	ft_update_time(t_philo *philo);
void	ft_update_time_last_meal(t_philo *philo);
int	ft_get_time(t_philo *philo);

#endif
