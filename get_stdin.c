/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stdin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 21:57:14 by kbensado          #+#    #+#             */
/*   Updated: 2016/04/15 21:57:15 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int		is_start_end(char *str)
{
	static int	sused = 0;
	static int	eused = 0;

	if (ft_strcmp(str, "##start") == 0)
	{
		if (sused == 1)
			return (0);
		sused = 1;
		return (1);
	}
	if (ft_strcmp(str, "##end") == 0)
	{
		if (eused == 1)
			return (0);
		eused = 1;
		return (2);
	}
	return (0);
}

static t_dock	*get_link(t_ants *list, t_dock *dock, int i, int j)
{
	t_dock		*begin;

	begin = dock;
	if (list == NULL || dock == NULL)
		return (0);
	list->n_room = j;
	list->index = i;
	dock->room = list->map;
	if (NA == 0)
		return (0);
	if (ft_strcmp("##start", MAP[i - 1]) == 0 || DD)
		return (0);
	if (is_start_end("##start") == 1 || is_start_end("##end") == 2)
		return (0);
	if (is_possible(begin, j, 0, list))
	{
		dock = begin;
		if (link_them(list, dock, ft_list_size(dock, j, NULL), list->index))
			return (begin);
	}
	return (0);
}

t_dock			*get_dock(t_ants *list, int i, int j, t_dock *dock)
{
	while (MAP[++i] != NULL)
	{
		ROOM = ft_strsplit(MAP[i], ' ');
		if (ROOM[0][0] == 'L')
			return (NULL);
		if (RO[2] && !RO[3] && RO[0][0] != '#' && !((ft_strchr(RO[0], '-'))))
		{
			if (NUM(RO[1]) && NUM(RO[2]) && CHECK)
				ft_dock_push_back(&dock, list, j);
			else
				return (NULL);
			j++;
		}
		if ((ROOM[1] == NULL) && (ft_strcmp(ROOM[0], "##end") == 0
			|| ft_strcmp(ROOM[0], "##start") == 0))
			if (!(list->start = is_start_end(ROOM[0])) || HH)
				return (NULL);
		if ((ROOM[1] == NULL) && (ROOM[0][0] == '#') && (ROOM[0][1] != '#'))
			continue ;
		if (ft_strchr(MAP[i], '-'))
			break ;
		free_char(ROOM, 0);
	}
	return (get_link(list, dock, i, j));
}

int				get_ants(t_ants *list, t_dock *dock, int i)
{
	int		*tab;

	dock = NULL;
	if ((ft_str_is_numericable(MAP[0])) && (MAP[1] != NULL))
		NA = ft_atoi(MAP[0]);
	else
		return (0);
	if (!(dock = get_dock(list, 0, 0, dock)))
		return (0);
	if (!(riset_matrice(dock, 0, ft_list_size(dock, 0, NULL), 0)))
		return (0);
	if (!(tab = (int *)malloc(sizeof(int) * list->n_room)))
		return (0);
	tab = set_tab(tab, NROOM);
	tab[i++] = find_start_end(dock, 1);
	if (ft_list_size(dock, 0, NULL) == 2)
		return (why_so_serious(dock, list));
	if (do_it(dock, 0, tab, NULL))
	{
		free_dock(&dock);
		free_ants(&list);
		free(tab);
		return (1);
	}
	return (0);
}

char			**get_stdin(t_ants *list, int i, int j, char *line)
{
	char		*buffer;

	buffer = ft_strnew(1);
	while (read(0, &*buffer, 1) != 0)
	{
		line = ft_strjoin(line, buffer);
		if (ft_isascii(line[i]) == 0)
			return (0);
		if (line[i] == '\n')
			j++;
		if (line[i] == '\n' && line[i - 1] == '\n')
		{
			j--;
			break ;
		}
		i++;
	}
	list->nb_line = j;
	if (ft_isdigit(line[0]) == 0)
		return (0);
	MAP = ft_strsplit(line, '\n');
	free(buffer);
	free(line);
	return (fu(MAP));
}
