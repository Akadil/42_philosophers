/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:21:03 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/30 15:46:29 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EAT_H
# define FT_EAT_H

# include "time.h"
# include "struct_philo.h"
# include <stdio.h>
# include <unistd.h>

int     ft_check_status(t_philo *philo);
void    ft_unlock_forks(t_philo *philo);

#endif
