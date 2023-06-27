/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:29:54 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/27 20:29:22 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_routine.h"

int	ft_is_my_turn2(t_philo *philo)
{
	if(philo->rules->num_philo % 2 == 0)
	{
		if (philo->num % 2 == 0)
			return (1);
		return (0);
	}
	if (philo->rules->num_philo == 1)
		return (1);
	philo->iter = philo->rules->num_philo / 2;
	philo->host = philo->num_meal % philo->rules->num_philo;
	while(philo->iter != 0)
	{
		if (philo->num % philo->rules->num_philo == philo->host)
			return (1);
		philo->host = philo->host + 2;
		if (philo->host > philo->rules->num_philo)
			philo->host = philo->host % philo->rules->num_philo;
		philo->iter--;
	}
	return (0);
}

void    ft_unlock_forks(t_philo *philo)
{
	if (ft_is_my_turn2(philo))
	{
		pthread_mutex_unlock(&philo->next->fork);
		pthread_mutex_unlock(&philo->fork);
	}
	else
	{
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->next->fork);
	}
}

void    *ft_routine(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    if (ft_start_schedule(philo) != 0)
        return (ft_handle_error(philo), NULL);
    while (1)
    {
        if (ft_fork(philo) != 0)
            break ;
        if (ft_eat(philo) != 0)
        {
            ft_unlock_forks(philo);
            break ;
        }
        ft_unlock_forks(philo);
        if (--philo->success == 0)
            break ; 
        if (ft_sleep(philo) != 0)
            break ;
    }
    if (philo->exit_code == -1 || philo->exit_code == -2)
        ft_handle_error(philo);
    return (NULL);
}
