/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 18:55:27 by kbensado          #+#    #+#             */
/*   Updated: 2016/05/03 18:55:29 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			len_tab(int *tab, int nb, int check)
{
	int		i;

	i = 0;
	while (i < nb)
	{
		if (tab[i] != -1)
		{
			if (check)
				ft_printf(" %d", tab[i]);
			i++;
		}
		else
		{
			if (check)
				ft_putchar('\n');
			return (i);
		}
	}
	if (check)
		ft_putchar('\n');
	return (i);
}

int			ft_nbrchr(int *tab, int target, int index)
{
	int		i;

	i = 0;
	while (i < index)
	{
		if (tab[i] == target)
			return (1);
		i++;
	}
	return (0);
}

int			*ft_tabdup(int *tab, int count)
{
	int		i;
	int		*tmp;

	i = 0;
	tmp = NULL;
	if (!(tmp = (int *)malloc(sizeof(int) * count)))
		return (NULL);
	while (i < count)
	{
		tmp[i] = tab[i];
		i++;
	}
	return (tmp);
}

void		ft_path_push_front(t_path **begin_list, int *tab, int nb, int end)
{
	t_path	*list;

	if (*begin_list)
	{
		list = ft_create_path(tab, nb, end);
		list->next = *begin_list;
		*begin_list = list;
	}
	else
		*begin_list = ft_create_path(tab, nb, end);
}

t_path		*ft_create_path(int *tab, int nb, int end)
{
	t_path	*list;

	list = NULL;
	list = malloc(sizeof(t_path));
	if (list)
	{
		list->nb_room = nb;
		list->len = len_tab(tab, nb, 0);
		list->tab = ft_tabdup(tab, nb);
		if (end == tab[--nb])
			list->end = 1;
		else
			list->end = 0;
		list->next = NULL;
	}
	return (list);
}
