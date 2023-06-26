/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:22:11 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/26 23:50:47 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SLEEP_H
# define FT_SLEEP_H

# include "struct_philo.h"
# include "ft_time.h"
# include <stdio.h>

int usleep_alt(t_philo *philo);
int ft_check_status(t_philo *philo);

#endif
