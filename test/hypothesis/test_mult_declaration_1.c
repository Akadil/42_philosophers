/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mult_declaration_1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:43:52 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/21 17:47:09 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void    ft_function(void);
void    ft_other_file(void);

/*
    Can I have multiple definition of one function across several files?

    Result:     Yes, I can do it
*/
int main(void)
{
    ft_function();
    ft_other_file();
    return (0);
}

void    ft_function(void)
{
    printf("Hello world!\n");
}