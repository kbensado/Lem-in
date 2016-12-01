/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 21:20:07 by kbensado          #+#    #+#             */
/*   Updated: 2016/04/20 21:20:09 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		ft_dock_push_back(t_dock **begin_list, t_ants *data, int j)
{
	t_dock	*list;

	list = *begin_list;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = ft_create_dock(data, j, NULL);
	}
	else
		*begin_list = ft_create_dock(data, j, NULL);
}

int			ft_list_size(t_dock *list, int nb, t_path *path)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (list)
	{
		i++;
		if (nb > 0)
			NROOM = nb;
		list = list->next;
	}
	while (path)
	{
		j++;
		path = path->next;
	}
	return (i);
}

t_dock		*ft_create_dock(t_ants *list, int j, t_dock *dock)
{
	dock = malloc(sizeof(t_dock));
	if (dock)
	{
		NAME = ft_strdup(ROOM[0]);
		A = ft_atoi(ROOM[1]);
		B = ft_atoi(ROOM[2]);
		KEY = j;
		if (list->start > 0)
		{
			if (list->start == 1)
				ANTS = NA;
			else
				ANTS = 0;
			POS = list->start;
			list->start = 0;
		}
		else
		{
			ANTS = 0;
			POS = 0;
		}
		DNEXT = NULL;
	}
	return (dock);
}

void		free_dock(t_dock **begin_list)
{
	t_dock	*list;
	t_dock	*temp;
	int		i;

	i = 0;
	if (*begin_list == NULL)
		return ;
	list = *begin_list;
	while (list)
	{
		temp = list->next;
		while (i < list->n_room)
		{
			free(list->map[i]);
			list->map[i++] = NULL;
		}
		if (list->name)
			free(list->name);
		if (list)
			free(list);
		list = temp;
	}
	*begin_list = NULL;
}

void		free_ants(t_ants **begin_list)
{
	t_ants	*list;
	int		i;

	i = 0;
	if (*begin_list == NULL)
		return ;
	list = *begin_list;
	if (list)
	{
		while (list->map[i] != NULL)
		{
			free(list->map[i]);
			list->map[i++] = NULL;
		}
		i = 0;
		while (list->room[i] != NULL)
		{
			free(list->room[i]);
			list->room[i++] = NULL;
		}
		if (list)
			free(list);
	}
	*begin_list = NULL;
}
