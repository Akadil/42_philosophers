/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:02:46 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/20 16:08:35 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_philo.h"

int ft_eat(t_philo *philo)
{
    int time_available;

    time_available = ft_available_time(); 
    if (time_available < 0)
    {
        pthread_mutex_unlock(&philo->mutex);
        ft_die();
        return (-1);
    }
    printf("%dms %d is eating\n", ft_get_time(), philo->num);
    ft_update_philo_time(philo);
    usleep(philo->rules->time_eat * 1000);
    return (0);
}