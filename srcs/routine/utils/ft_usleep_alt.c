/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep_alt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:37:46 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/27 14:43:52 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "struct_philo.h"

int ft_check_status(t_philo *philo);

int usleep_alt(t_philo *philo)
{
    while (philo->time_skip > 100)
    {
        if (usleep(100) == -1)
        {
            philo->exit_code = -2;
            return (-1);
        }
        if (ft_check_status(philo) != 0)
            return (-1);
        philo->time_skip = philo->time_skip - 100;
    }
    if (philo->time_skip > 0 && usleep(philo->time_skip) == -1)
    {
        philo->exit_code = -2;
        return (-1);
    }
    return (0);
}
