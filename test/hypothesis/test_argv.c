/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_argv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:03:08 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/20 11:06:23 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/*
    Question:   What was the arg values 
*/

int main(int argc, char **argv)
{
    int i;

    i = 0;
    printf("The argc is %d\n", argc);
    while (argv[i])
    {
        printf("%s \n", argv[i]);
        i++;
    }
}