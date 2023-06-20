/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettimeofday.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:41:44 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/20 14:53:31 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stdio.h>

int main(void)
{
    struct timeval time;

    if (gettimeofday(&time, NULL) != 0)
        return (printf("some problems\n"), -1);
    printf("Hello world: %ld and %ld", time.tv_sec % 1000, time.tv_usec);
    return (0);
}