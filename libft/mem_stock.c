/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_stock.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 22:04:15 by bandre            #+#    #+#             */
/*   Updated: 2017/03/15 23:53:08 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_mem_stock		**mem_ptr(void)
{
	static t_mem_stock *list = NULL;

	return (&list);
}

static t_mem_stock	*init_list(void)
{
	t_mem_stock *list;

	list = (t_mem_stock*)ft_strnew(sizeof(t_mem_stock));
	if (!list)
		return (NULL);
	list->list_ptr = (void*)ft_strnew(sizeof(void*) * 51);
	if (!list->list_ptr)
		return (NULL);
	return (list);
}

static	void		*mem_add(t_mem_stock *list, int i)
{
	int j;

	j = 0;
	while (list->next)
		list = list->next;
	while (list->list_ptr[j] != NULL && j < 50)
		j++;
	if (j == 50)
	{
		if (!(list->next = init_list()))
			return (NULL);
		list = list->next;
		j = 0;
	}
	if (!(list->list_ptr[j] = (void*)ft_strnew(i)))
		return (NULL);
	return (list->list_ptr[j]);
}

void		*mem_stock(int i)
{
	t_mem_stock **list;

	list = mem_ptr();
	if (*list == NULL)
		if (!(*list = init_list()))
			return (NULL);
	return (mem_add(*list, i));
}

