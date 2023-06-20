/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:33:02 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/20 16:40:57 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stdio.h>
#include "ft_error.h"

/**
 * @brief       get current time
 * 
 * @return int  current time in milliseconds, -1 if error occured
 */
int    ft_get_time()
{
    struct timeval  timeval;
    int             curr_time;
    
    if (gettimevalofday(&timeval, NULL) != 0)
        return (ft_error(), -1);
    curr_time = timeval.tv_sec * 1000 + timeval.tv_usec / 1000;
    return (curr_time);
}
