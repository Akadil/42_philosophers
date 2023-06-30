/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_status.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 23:48:50 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/30 15:26:12 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_philo.h"
#include <pthread.h>

int	ft_check_status(t_philo *philo)
{
	pthread_mutex_lock(&philo->exit);
	if (philo->exit_code != 0)
	{
		pthread_mutex_unlock(&philo->exit);
		return (-1);
	}
	pthread_mutex_unlock(&philo->exit);
	return (0);
}
