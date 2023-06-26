/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 10:56:37 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/26 23:42:42 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_parsing.h"
#include <sys/time.h>

void    ft_parsing(int argc, char **argv, t_rules *rules)
{
    struct timeval  timeval;

    if (argc - 1 != 4 && argc - 1 != 5)
        ft_merror_d_exit("%d: wrong number of arguments\n", argc - 1);
    ft_parsing_num_philo(argv, rules);
    ft_parsing_time_to_die(argv, rules);
    ft_parsing_time_to_eat(argv, rules);
    ft_parsing_time_to_sleep(argv, rules);
    ft_parsing_num_success(argc, argv, rules);
    rules->status_code = 0;
    if (rules->time_die <= rules->time_eat + rules->time_sleep)
        ft_merror_exit("Wrong time inputs! t_die > t_eat + t_sleep\n", NULL);
    if (gettimeofday(&timeval, NULL) != 0)
        ft_error_exit();
    if (pthread_mutex_init(&rules->exit, NULL) != 0)
        ft_error_exit();
    rules->time_start = ((timeval.tv_sec + 3) * 1000 % 100000000) + (timeval.tv_usec / 1000);
}
