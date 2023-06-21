/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_if_negative.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:02:40 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/21 12:06:02 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int function();

/*
    How does if condition respond to function return value

    Result: "Inside"
    
    Conclusion: if function itself in the if condition statement, then only 
                0 will give false result
*/
int main(void)
{
    if (function())
        printf("Inside\n");
    else
        printf("Outside\n");
    return (0);
}

int function()
{
    return (-1);
}
