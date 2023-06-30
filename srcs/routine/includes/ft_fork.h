/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:21:42 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/30 15:42:14 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FORK_H
# define FT_FORK_H

# include "time.h"
# include "struct_philo.h"
# include <pthread.h>
# include <stdio.h>

int		ft_check_status(t_philo *philo);
void	ft_lock_forks(t_philo *philo);
void	ft_unlock_forks(t_philo *philo);

#endif
