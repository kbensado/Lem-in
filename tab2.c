/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 21:02:50 by kbensado          #+#    #+#             */
/*   Updated: 2016/05/06 21:02:51 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		*set_next(int *tab, int i, int count)
{
	while (i < count)
	{
		tab[i] = -1;
		i++;
	}
	return (tab);
}

int		ft_tabcmp(int *tab, int *tab2, int count)
{
	int i;

	i = 0;
	while (i < count)
	{
		if (tab[i] == tab2[i])
			i++;
		else
			return (0);
	}
	return (1);
}

int		*catch_it(int *tab, int end, int i, int index)
{
	while (i < index)
	{
		if (tab[i] == end)
		{
			i++;
			while (i < index)
				tab[i++] = -1;
			return (tab);
		}
		else
			i++;
	}
	return (NULL);
}

int		*set_tab(int *tab, int nb)
{
	int i;

	i = 0;
	while (i < nb)
	{
		tab[i] = -1;
		i++;
	}
	return (tab);
}
