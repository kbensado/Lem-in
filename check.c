/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 19:13:01 by kbensado          #+#    #+#             */
/*   Updated: 2016/04/19 19:14:32 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int				found_key(t_dock *dock, char *room)
{
	while (dock)
	{
		if (strcmp(room, NAME) == 0)
			return (KEY);
		dock = DNEXT;
	}
	return (-1);
}

int				link_them(t_ants *list, t_dock *dock, int j, int i)
{
	DOCK = set_double_tab(j, 0, 0);
	while (MAP[i])
	{
		ROOM = ft_strsplit(MAP[i++], ' ');
		if ((ROOM[1] == NULL) && (ft_strchr(ROOM[0], '-')
			!= NULL && ROOM[0][0] != '#'))
		{
			ROOM = ft_strsplit(ROOM[0], '-');
			CHECK = 0;
			if (found_key(dock, RO[0]) != -1 && found_key(dock, ROOM[1]) != -1)
				DOCK = set_matrice(dock, ROOM);
			else
				return (0);
		}
		else if (ROOM[0][0] == '#' && GG)
		{
			free_char(ROOM, 0);
			continue ;
		}
		else
			return (0);
		free_char(ROOM, 0);
	}
	copy_tab(dock, j, 0);
	return (1);
}

int				is_possible(t_dock *dock, int i, int j, t_ants *list)
{
	t_dock		*begin;
	char		*tmp;
	int			tmp2;
	int			tmp3;

	begin = dock;
	tmp = NAME;
	tmp2 = A;
	tmp3 = B;
	if (DNEXT)
		dock = DNEXT;
	else
		return (1);
	while (dock)
	{
		if (ft_strcmp(tmp, NAME) == 0 || (tmp2 == A && tmp3 == B))
			return (0);
		dock = DNEXT;
	}
	dock = begin;
	if (DNEXT != NULL)
		return (is_possible(DNEXT, i, j + 1, list));
	return (0);
}
