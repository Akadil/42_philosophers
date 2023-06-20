/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_rules.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 10:44:52 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/20 16:29:13 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_RULES_H
# define STRUCT_RULES_H

/*
    status_code:
        0   - everything is code
        -1  - someone died
        -2  - some other error
*/
typedef struct s_rules
{
    int num_philo;
    int time_die;
    int time_sleep;
    int time_eat;
    int num_success;

    int status_code;
}   t_rules;

#endif
