/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:03:06 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/20 16:55:32 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_philo.h"

int ft_is_my_turn(t_philo *philo);
int ft_fork_left(t_philo *philo);
int ft_fork_right(t_philo *philo);

int ft_fork(t_philo *philo)
{
    while(ft_is_my_turn(philo) == 0)
        if (ft_think() == -1);
    if (ft_fork_left(philo) != 0)
        return (-1);
    if (ft_fork_right(philo) != 0)
        return (-1);
}

int ft_fork_left(t_philo *philo)
{
    // if (philo->status == 1)
    //     ft_think(philo);
    // else
    while (philo->prev->status == 1)
    {
        if (usleep_alt(100, philo) == -1)
            return (-2);
        if (philo->rules->status_code != 0)
            return (-3);
        if (ft_available_time(philo) < 0)
        {
            
        }
    }
    pthread_mutex_lock(&philo->mutex);
}

int ft_fork_right(t_philo *philo)
{
    // if (philo->status == 1)
    //     ft_think(philo);
    // else
    pthread_mutex_lock(&philo->next->mutex);
    printf("%dms %d has taken fork!\n", ft_get_time(), philo->num);
}

int ft_is_my_turn(t_philo *philo)
{
    int host;
    int num_iterations;
    int i;

    num_iterations = philo->rules->num_philo / 2;
    host = philo->round % philo->rules->num_philo;
    i = 0;
    while(i < num_iterations)
    {
        if (philo->num == host)
            return (1);
        host = host + 2;
        if (host > philo->rules->num_philo)
            host = host % philo->rules->num_philo;
        i++;
    }
    return (0);
}