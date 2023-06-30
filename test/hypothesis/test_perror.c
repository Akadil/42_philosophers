/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_perror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:19:42 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/30 15:24:06 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>

/*
    Hypothesis:     What will be the output if I pass NULL to perror function

    Result:         That's true. If NULL, then no ":" in it
*/

int main(void)
{
    int fd;

    fd = open("I_DONT_EXIST", O_RDONLY);
    if (fd == -1)
        perror(NULL);
    else
        printf("Something was wrong!\n");
}