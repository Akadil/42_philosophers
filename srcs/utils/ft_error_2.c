/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 12:51:49 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/28 13:14:01 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

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
