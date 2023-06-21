/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep_alt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:37:46 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/22 00:14:15 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "struct_philo.h"

int usleep_alt(t_philo *philo)
{
    while (philo->time_skip > 10000)
    {
        if (usleep(10000) == -1)
            return (-2);
        if (philo->rules->status_code != 0)
            return (-3);
        philo->time_skip -= 10000;
    }
    if (philo->time_skip > 0 && usleep(philo->time_skip) == -1)
        return (-2);
    return (0);
}
