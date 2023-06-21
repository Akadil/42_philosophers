/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:08:40 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/21 16:14:07 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_rules.h"
#include "libft.h"
#include "ft_error.h"

void    ft_parsing_num_philo(char **argv, t_rules *rules)
{
    if (ft_isnum(argv[1]) == 0)
        ft_merror_exit("%s: Wrong type of \"Number of Philos\"\n", argv[1]);
    if (argv[1][0] == '-')
        ft_merror_exit("%s: \"Number of philos\" can't be negative", argv[1]);
    rules->num_philo = ft_atoi(argv[1]);
}

void    ft_parsing_time_to_die(char **argv, t_rules *rules)
{
    if (ft_isnum(argv[2]) == 0)
        ft_merror_exit("%s: Wrong type of \"Time to die\"\n", argv[2]);
    if (argv[2][0] == '-')
        ft_merror_exit("%s: \"Time to die\" can't be negative", argv[2]);
    rules->time_die = ft_atoi(argv[2]);
}

void    ft_parsing_time_to_eat(char **argv, t_rules *rules)
{
    if (ft_isnum(argv[3]) == 0)
        ft_merror_exit("%s: Wrong type of \"Time to eat\"\n", argv[3]);
    if (argv[3][0] == '-')
        ft_merror_exit("%s: \"Time to eat\" can't be negative", argv[3]);
    rules->time_eat = ft_atoi(argv[3]);
}

void    ft_parsing_time_to_sleep(char **argv, t_rules *rules)
{
    if (ft_isnum(argv[4]) == 0)
        ft_merror_exit("%s: Wrong type of \"Time to sleep\"\n", argv[4]);
    if (argv[4][0] == '-')
        ft_merror_exit("%s: \"Time to sleep\" can't be negative", argv[4]);
    rules->time_sleep = ft_atoi(argv[4]);
}

void    ft_parsing_num_success(int argc, char **argv, t_rules *rules)
{
    if (argc == 5)
        rules->num_success = -1;
    else
    {
        if (ft_isnum(argv[5]) == 0)
            ft_merror_exit("%s: Wrong type of \"number of success\"\n", argv[5]);
        if (argv[5][0] == '-')
            ft_merror_exit("%s: \"number of success\" can't be negative", argv[5]);
        rules->num_success = ft_atoi(argv[5]);
    }
}