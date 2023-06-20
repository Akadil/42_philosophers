/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:36:44 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/20 16:38:21 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H

void    ft_perror(char *str);
void    ft_merror(char *str, char *param);
void    ft_merror_d(char *str, int num);
void    ft_error();

#endif
