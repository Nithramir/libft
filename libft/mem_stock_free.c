/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_stock_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 22:38:53 by bandre            #+#    #+#             */
/*   Updated: 2017/03/15 23:50:50 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void free_void(t_mem_stock *list)
{
	int j;

	j = 0;
	while (list->list_ptr[j])
	{
		free(list->list_ptr[j]);
		j++;
	}
	free(list->list_ptr);
}

void	mem_stock_free(void)
{
	t_mem_stock **list;
	t_mem_stock *tmp;

	list = mem_ptr();
	while (*list)
	{
		free_void(*list);
		tmp = (*list)->next;
		free(*list);
		*list = tmp;
	}
}

