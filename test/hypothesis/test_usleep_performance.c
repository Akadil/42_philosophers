/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_usleep_performance.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 00:15:16 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/22 00:28:11 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/time.h>
#include <stdio.h>

/*
    Test the time performance of usleep

    Result:         for t = 100, fail_percent = 150%
                        t = 1000, fail_persent = 10%
                        t = 10000, fail_percent = 1%

    Conclusion:     The less I take the more error I have
*/

int main(void)
{
    struct timeval  timeval;
    int             time;

    gettimeofday(&timeval, NULL);
    printf("Current time: %ld\n", (timeval.tv_usec) % 1000000);
    
    usleep(10000);

    gettimeofday(&timeval, NULL);
    printf("Current time: %ld\n", (timeval.tv_usec) % 1000000);
    return (0);
}