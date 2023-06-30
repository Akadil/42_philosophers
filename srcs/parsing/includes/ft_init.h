/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:18:48 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/28 12:47:41 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INIT_H
# define FT_INIT_H

# include "ft_error.h"
# include "struct_philo.h"
# include "struct_rules.h"
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>

t_philo	*ft_lstlast_alt(t_philo *philo);
void	ft_lstadd_back_alt(t_philo **head, t_philo *philo);
void	ft_connect_first_last(t_philo *philo);

#endif
