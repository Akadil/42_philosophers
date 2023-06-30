/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:08:38 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/30 15:35:28 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_sleep.h"

int	ft_sleep(t_philo *philo)
{
	if (ft_update_time(philo) != 0)
		return (-1);
	if (ft_check_status(philo) != 0)
		return (-1);
	printf("[%7dms] %3d is sleeping\n", ft_get_time(philo), philo->num);
	if (usleep(philo->rules->time_sleep * 1000) != 0)
		return (-1);
	if (ft_update_time(philo) != 0)
		return (-1);
	if (ft_check_status(philo) != 0)
		return (-1);
	printf("[%7dms] %3d is thinking\n", ft_get_time(philo), philo->num);
	return (0);
}
