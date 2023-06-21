/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:28:34 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/21 22:17:06 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_philo.h"
#include "libft.h"
#include "../includes/ft_time.h"
#include "ft_error.h"
#include <stdio.h>

void    ft_set_status(t_philo *philo, int exit_code)
{
    philo->rules->status_code = exit_code;
}

void    ft_handle_error(t_philo *philo)
{
	philo->rules->status_code = philo->exit_code;
	if (philo->exit_code == -1)
	{
		if (ft_get_time(philo) != 0)
		{
			ft_perror_d(philo->num);
			return ;
		}
		philo->time_curr = philo->time_curr - philo->rules->time_start;
		printf("%dms %d died", philo->time_curr, philo->num);
	}
	else if (philo->exit_code == -2)
		ft_perror_d(philo->num);
}
