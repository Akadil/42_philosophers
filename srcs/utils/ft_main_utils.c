/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:27:09 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/27 19:27:45 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "struct_philo.h"
#include "ft_clean.h"
#include <errno.h>
#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>

void	ft_set_all_statuses2(t_philo *philo, int ind)
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
        if (ind == i)
    		philo->exit_global = -1;
        else
            philo->exit_global = -2;
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

void    ft_monitor(t_philo *philo, t_rules *rules)
{
    struct timeval  tv;
    int             i;
    int time;
    int exit;

    exit = 0;
    while (exit == 0)
    {
        if (gettimeofday(&tv, NULL) != 0)
            return ;
        time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
        i = 0;
        while (i < rules->num_philo)
        {
            // have stopping condition for 5th element
            pthread_mutex_lock(&philo->meal);
            if (time - philo->time_eat > rules->time_die)
            {
                pthread_mutex_unlock(&philo->meal);
                pthread_mutex_lock(&rules->exit);
                ft_set_all_statuses2(philo, i);
                pthread_mutex_unlock(&rules->exit);
                exit = 1;
                break ;
            }
            pthread_mutex_unlock(&philo->meal);
            usleep(100);
            philo = philo->next;
            i++;
        }
    }
    usleep(1000);
}

int    ft_close_threads(t_philo *philo, t_rules *rules, int pos)
{
    t_philo *temp;
    int     i;

    ft_monitor(philo, rules);
    i = 0;
    temp = philo;
    while (i < rules->num_philo)
    {
        if (pthread_join(temp->id, NULL) != 0)
            return (-1);
        temp = temp->next;
        i++;
    }
    temp = philo->prev;
    if (temp)
        temp->next = NULL;
    philo->prev = NULL;
    temp = philo;
    ft_clean_alt(philo, pos);
    if (rules->status_code == 0)
        return (0);
    else if (rules->status_code == -1)
        return (-1);
    return (errno);
}
