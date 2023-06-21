/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mutex_in_function.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 19:57:18 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/21 20:08:23 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>

/*
    Check the nature of the mutex
*/

pthread_mutex_t a;

void    *routine(void *arg)
{
    int     qwe;

    (void)arg;
    pthread_mutex_lock(&a);
    qwe = 16;
    usleep (1000000);
    printf("My num is %d\n", qwe);
    pthread_mutex_unlock(&a);
    return (NULL);
}

int main(void)
{
    pthread_t p1;
    pthread_t p2;
    pthread_mutex_init(&a, NULL);
    pthread_create(&p1, NULL, &routine, NULL);
    usleep (100000);
    pthread_create(&p2, NULL, &routine, NULL);
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    return (0);
}