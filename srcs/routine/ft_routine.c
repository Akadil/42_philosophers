/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:29:54 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/30 15:51:45 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_routine.h"

void	*ft_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (ft_start_schedule(philo) != 0)
		return (ft_handle_error(philo), NULL);
	if (philo->rules->num_philo == 1)
		return (ft_handle_one_philo(philo), NULL);
	while (1)
	{
		if (ft_fork(philo) != 0)
			break ;
		if (ft_eat(philo) != 0)
			break ;
		if (philo->num_meal == philo->rules->num_success)
			break ;
		if (ft_sleep(philo) != 0)
			break ;
	}
	if (philo->exit_code == -2)
		ft_handle_error(philo);
	ft_set_end_status(philo);
	return (NULL);
}
