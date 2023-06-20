/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 10:56:37 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/20 12:36:58 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include "struct_rules.h"
#include "struct_list.h"

void ft_parsing(int argc, char **argv, t_rules *rules, t_list *philos)
{
    if (argc - 1 != 4 && argc - 1 != 5)
        ft_merror2_exit("%d: wrong number of arguments\n", argc - 1);
    if (ft_isnum(argv[1]) == 0)
        ft_merror_exit("%s: Wrong type of number of Philos\n", argv[1]);
    if (argv[1][0] && argv[1][0] == '-')
        ft_merror_exit("%s: Number of philos can't be ", NULL);
    // And all this stuff

    rules->is_died = 0;
    rules->num_philo = ft_atoi(argv[1]);
    rules->time_die = ft_atoi(argv[2]);
    rules->time_eat = ft_atoi(argv[3]);
    rules->time_sleep = ft_atoi(argv[4]);
    rules->num_success = ft_atoi(argv[5]);

}