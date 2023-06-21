/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 10:56:37 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/21 22:02:10 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_parsing.h"

void    ft_parsing(int argc, char **argv, t_rules *rules)
{
    if (argc - 1 != 4 && argc - 1 != 5)
        ft_merror_d_exit("%d: wrong number of arguments\n", argc - 1);
    ft_parsing_num_philo(argv, rules);
    ft_parsing_time_to_die(argv, rules);
    ft_parsing_time_to_eat(argv, rules);
    ft_parsing_time_to_sleep(argv, rules);
    ft_parsing_num_success(argc, argv, rules);
    rules->status_code = 0;
    rules->time_start = -1;
    // Add some extra rules like Alexi said
}
