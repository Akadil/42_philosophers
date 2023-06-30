/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 10:50:38 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/28 12:48:19 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAIN_H
# define FT_MAIN_H

# include "ft_clean.h"
# include "struct_philo.h"
# include "struct_rules.h"
# include <pthread.h>
# include <stdio.h>

void	ft_parsing(int argc, char **argv, t_rules *rules);
t_philo	*ft_init(t_rules *rules);
void	*ft_routine(void *arg);
int		ft_close_threads(t_philo *philo, t_rules *rules, int pos);

#endif