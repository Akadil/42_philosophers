/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:36:44 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/21 17:30:33 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H

# include "struct_philo.h"

void    ft_error(void);
void	ft_error_clean_exit(t_philo *philo);

void    ft_perror(char *str);
void	ft_perror_d(int num);

void    ft_merror(char *str, char *param);
void	ft_merror_exit(char *str, char *param);;

void    ft_merror_d(char *str, int num);
void	ft_merror_d_exit(char *str, int param);

#endif
