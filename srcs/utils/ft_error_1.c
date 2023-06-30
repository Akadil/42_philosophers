/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:30:15 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/28 12:52:05 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_clean.h"
#include "ft_error.h"
#include "libft.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	ft_error(void)
{
	ft_printf2("%s\n", strerror(errno));
}

void	ft_error_exit(void)
{
	ft_error();
	exit(-1);
}

void	ft_error_clean_exit(t_philo *philo)
{
	ft_error();
	ft_clean(philo);
	exit(errno);
}

void	ft_perror(char *str)
{
	perror(str);
}

void	ft_perror_d(int num)
{
	ft_printf2("%d: %s\n", num, strerror(errno));
}
