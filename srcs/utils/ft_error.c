/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:30:15 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/21 17:57:19 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"
#include "ft_clean.h"
#include "libft.h"
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>

void	ft_error(void)
{
	ft_printf2("%s\n", strerror(errno));
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

void	ft_merror(char *str, char *param)
{
	ft_printf2(str, param);
}

void	ft_merror_exit(char *str, char *param)
{
	ft_merror(str, param);
	exit(-1);
}

void	ft_merror_d(char *str, int param)
{
	ft_printf2(str, param);
}

void	ft_merror_d_exit(char *str, int param)
{
	ft_merror_d(str, param);
	exit(-1);
}
