/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 16:17:04 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/30 19:16:40 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_monitor.h"

void ft_run_monitoring(t_philo *philo)
{
    struct timeval	tv;
	int				time;

	while (1)
	{
		if (gettimeofday(&tv, NULL) != 0)
			return ;
		time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
		if (ft_is_game_finished(philo) == 1)
			break ;
		if (ft_check_death(philo, philo->rules, time) == 0)
			break ;
	}
	usleep(10000);
}

int	ft_is_game_finished(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->rules->num_philo)
	{
		pthread_mutex_lock(&philo->exit);
		philo = philo->next;
        i++;
	}
	i = 0;
	while (i < philo->rules->num_philo)
	{
		if (philo->exit_code != -4)
			return (0);
		philo = philo->next;
        i++;
	}
	i = 0;
	while (i < philo->rules->num_philo)
	{
		pthread_mutex_unlock(&philo->exit);
		philo = philo->next;
        i++;
	}
	return (1);
}

int	ft_check_death(t_philo *philo, t_rules *rules, int time)
{
	int	i;
    int time_meal;

	i = 0;
	while (i < rules->num_philo)
	{
		pthread_mutex_lock(&philo->meal);
        time_meal = philo->time_eat; 
		pthread_mutex_unlock(&philo->meal);
        if (time - time_meal > rules->time_die)
		{
			pthread_mutex_lock(&rules->exit);
			ft_set_all_statuses_2(philo);
			printf("[%7dms] %3d died\n", time - rules->time_start, philo->num);
			pthread_mutex_unlock(&rules->exit);
			return (0);
		}
		usleep(100);
		philo = philo->next;
		i++;
	}
	return (1);
}

void	ft_set_all_statuses_2(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->rules->num_philo)
	{
		pthread_mutex_lock(&philo->exit);
		philo = philo->next;
		i++;
	}
	i = 0;
	while (i < philo->rules->num_philo)
	{
		philo->exit_code = -3;
		philo = philo->next;
		i++;
	}
	i = 0;
	while (i < philo->rules->num_philo)
	{
		pthread_mutex_unlock(&philo->exit);
		philo = philo->next;
		i++;
	}
}
