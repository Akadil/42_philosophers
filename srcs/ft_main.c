/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:40:06 by akadilkalim       #+#    #+#             */
/*   Updated: 2023/06/30 18:54:27 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_main.h"

int	main(int argc, char **argv)
{
	t_philo	*philo;
	t_rules	rules;
	int		i;

	ft_parsing(argc, argv, &rules);
	philo = ft_init(&rules);
	i = 0;
	while (i < rules.num_philo)
	{
		if (pthread_create(&philo->id, NULL, &ft_routine, philo) != 0)
			break ;
		philo = philo->next;
		i++;
	}
	ft_run_monitoring(philo);
	return (ft_close_threads(philo, &rules, i));
}
