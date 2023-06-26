/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_data_race_accessNeighbour.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 20:36:11 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/26 20:44:30 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include "libft.h"

/*  Question:   Can I access the neigbour's structure (not variable)    */

/*  Result:     Yes, I can use it                                       */

/*  Checker:    cc -Iincludes -Wall -Werror -Wextra -pthread -fsanitize=thread test/hypothesis/test_data_race_accessNeighbour.c -Llibft -lft    */

void	*routine(void   *arg)
{
    t_list  *list;

    list = (t_list *)arg;
	printf("Hello World!\n");
	printf("My name is %s\n", (char *)list->next->content);
	return (NULL);
}

int main(void)
{
    t_list  *list;
    pthread_t	t1;
	pthread_t	t2;

    list = NULL;
    ft_lstadd_back(&list, ft_lstnew("Akadil", 0));
    ft_lstadd_back(&list, ft_lstnew("Kalimoldayev", 1));
    list->prev = list->next;
    list->next->next = list;

	pthread_create(&t1, NULL, &routine, list);
	pthread_create(&t2, NULL, &routine, list->next);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

    return (0);
}