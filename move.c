/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 03:54:40 by kbensado          #+#    #+#             */
/*   Updated: 2016/05/10 03:54:41 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int				free_path(t_path **begin_list)
{
	t_path		*list;
	t_path		*temp;

	if (*begin_list == NULL)
		return (1);
	list = *begin_list;
	while (list)
	{
		temp = list->next;
		if (list->tab)
			free(list->tab);
		if (list)
			free(list);
		list = temp;
	}
	*begin_list = NULL;
	return (1);
}

int				get_nbants(t_dock *dock, int i)
{
	int			ants;

	while (POS != i)
		dock = DNEXT;
	ants = ANTS;
	return (ants);
}

int				*get_low(t_path *path, t_dock *dock)
{
	int			count;
	int			*tab;

	count = len_tab(PATH, NROOM2, 0);
	while (path != NULL)
	{
		if (count > len_tab(PATH, NROOM2, 0) && len_tab(PATH, NROOM2, 0) > 1)
			count = len_tab(PATH, NROOM2, 0);
		if (NPATH)
			path = NPATH;
		else
			break ;
	}
	tab = PATH;
	return (tab);
}

static void		print_dock(int key, t_dock *dock, int tmp, int actual)
{
	static int	check = 1;
	int			i;

	i = 0;
	if (check == 1)
	{
		while (dock->room[i])
			WS(dock->room[i++]);
		ft_putchar('\n');
		check = 0;
	}
	if (actual == -1)
		return ;
	while (key != KEY && dock != NULL)
		dock = DNEXT;
	ft_printf("L%d-%s ", tmp - actual, NAME);
}

int				move(t_path *path, t_dock *dock, int tmp, int *tab)
{
	int			hill[len_tab(tab, NROOM2, 0) - 1];
	int			i;
	int			j;

	i = 0;
	j = 2;
	while (i < COUNT)
		hill[i++] = tmp;
	i = 0;
	while (hill[0] != -1 || (hill[COUNT - 1] != 0))
	{
		while (i < j)
		{
			if (hill[i] != -1)
				hill[i++]--;
			else
				i++;
		}
		while (--i > 0)
			print_dock(tab[i], dock, tmp, hill[i]);
		ft_putchar('\n');
		if (j < COUNT)
			j++;
	}
	return (free_path(&path));
}
