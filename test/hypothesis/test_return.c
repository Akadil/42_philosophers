/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_return.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:34:07 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/22 12:38:00 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/*
    I know that in order to stop void returnting function, I have to just
                    return ;
    but can I put some functions there? 

    Result:     No, it is better to transform the function into void *function
                and just doesn't receive anything in other side
*/

void    *ft_function(void)
{
    return (printf("Hello World\n"), NULL);
}

int main(void)
{
    ft_function();

    return (0);
}