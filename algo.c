/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 21:48:57 by kbensado          #+#    #+#             */
/*   Updated: 2016/04/15 21:48:59 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			find_start_end(t_dock *dock, int i)
{
	int		key;

	while (POS != i)
		dock = DNEXT;
	key = KEY;
	return (key);
}

static int	is_another(int base, int i, t_dock *dock, int *tab)
{
	if (tab[i] == find_start_end(dock, 2))
		return (tab[i]);
	while (i < NROOM2)
	{
		if (DOCK[base][i] > 0 && ft_nbrchr(tab, i, NROOM2) == 0)
			return (i);
		else
			i++;
	}
	return (-1);
}

int			do_it(t_dock *dock, int i, int *tab, t_path *path)
{
	while (++i < NROOM2 && i != -1 && path == NULL && FF)
	{
		tab[i] = is_another(tab[i - 1], tab[i], dock, tab);
		if (tab[i] == find_start_end(dock, 2) || tab[i] == -1)
		{
			if (tab[i] == find_start_end(dock, 2))
				ft_path_push_front(&path, tab, NROOM2, find_start_end(dock, 2));
			while (i > 0 && path == NULL)
			{
				tab[i] = is_another(tab[i - 1], tab[i], dock, tab);
				if (tab[i] == -1)
				{
					if (i-- == 1)
						return (0);
				}
				else
					break ;
			}
		}
	}
	if ((tab = catch_it(tab, FIND, 0, NROOM2)) && no_else(path, tab, 0) != 0)
		ft_path_push_front(&path, tab, NROOM2, find_start_end(dock, 2));
	if (len_tab(tab, NROOM2, 0) == 2)
		return (agent_of_chaos(dock, path));
	return (move(path, dock, get_nbants(dock, 1), get_low(path, dock)));
}
