/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 10:50:38 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/21 20:39:58 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAIN_H
# define FT_MAIN_H

# include <pthread.h>
# include "struct_rules.h"
# include "struct_philo.h"
# include "ft_clean.h"
# include <stdio.h>


void    ft_parsing(int argc, char **argv, t_rules *rules);
t_philo *ft_init(t_rules *rules);
void    *ft_routine(void *arg);
int    ft_close_threads(t_philo *philo, t_rules *rules, int pos);

#endif