/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akadilkalimoldayev <akadilkalimoldayev@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:09:25 by akadilkalim       #+#    #+#             */
/*   Updated: 2023/06/12 16:11:18 by akadilkalim      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_isnum(char *str)
{
    int i;

    i = 0;
    if (!str)
        return (0);
    if (str[i] == '-')
        i++;
    while (str[i])
    {
        if (str[i] > '9' || str[i] < '0')
            return (0);
        i++;
    }
    return (1);
}