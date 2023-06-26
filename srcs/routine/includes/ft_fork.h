/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:21:42 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/26 23:50:39 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FORK_H
# define FT_FORK_H

# include "struct_philo.h"
# include "exit_code.h"
# include <pthread.h>
# include <stdio.h>
# include "ft_time.h"
# include <unistd.h>

int ft_is_my_turn(t_philo *philo);
int ft_fork_left(t_philo *philo);
int ft_fork_right(t_philo *philo);
int ft_think(t_philo *philo);
int usleep_alt(t_philo *philo);
int ft_check_status(t_philo *philo);

#endif
