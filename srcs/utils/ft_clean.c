/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:30:59 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/28 12:44:29 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_philo.h"
#include <pthread.h>
#include <stdlib.h>

void	ft_clean(t_philo *philo)
{
	t_philo	*temp;

	while (philo)
	{
		temp = philo->next;
		pthread_mutex_destroy(&philo->fork);
		free(philo);
		philo = temp;
	}
}

void	ft_clean_alt(t_philo *philo, int pos)
{
	t_philo	*temp;
	int		i;

	i = 0;
	while (philo)
	{
		temp = philo->next;
		if (i < pos)
			pthread_mutex_destroy(&philo->fork);
		free(philo);
		philo = temp;
		i++;
	}
}
