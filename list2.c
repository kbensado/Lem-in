/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 19:56:10 by kbensado          #+#    #+#             */
/*   Updated: 2016/05/09 19:56:11 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

char		*get_name(t_dock *dock, int key)
{
	while (key != KEY)
		DNEXT = dock;
	return (NAME);
}

void		check_path_list(t_path *path)
{
	while (path)
	{
		if (path->next)
			path = path->next;
		else
			break ;
	}
}

int			no_else(t_path *path, int *tab, int i)
{
	if (path == NULL)
		return (1);
	else
	{
		while (path->next)
			path = path->next;
		while (i < path->nb_room)
		{
			if (PATH[i] == tab[i])
				i++;
			else
				return (1);
		}
		return (0);
	}
}

int			free_list_path(t_path *path)
{
	t_path	*tmp;
	t_path	*tmpnext;

	tmp = path;
	while (tmp != NULL)
	{
		tmpnext = tmp->next;
		free(tmp->tab);
		free(tmp);
		tmp = tmpnext;
	}
	return (0);
}

t_ants		*init_ants(t_ants *list)
{
	if (!(list = malloc(sizeof(t_ants))))
		return (NULL);
	NA = 0;
	MAP = NULL;
	ROOM = NULL;
	CHECK = 1;
	return (list);
}
