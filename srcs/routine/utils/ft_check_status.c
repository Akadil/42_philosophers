/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_status.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 23:48:50 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/27 16:21:56 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "struct_philo.h"

int ft_check_status(t_philo *philo)
{
    pthread_mutex_lock(&philo->exit);
    if (philo->exit_global != 0)
    {
        if (philo->exit_global == -1)
            philo->exit_code = -3;
        else
            philo->exit_code = -1;
        pthread_mutex_unlock(&philo->exit);   
        return (-1);
    }
    pthread_mutex_unlock(&philo->exit);
    return (0);
}