/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 01:42:40 by kbensado          #+#    #+#             */
/*   Updated: 2016/05/05 01:42:42 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			riset_matrice(t_dock *dock, int i, int count, int j)
{
	int		start;
	int		end;
	int		k;

	k = 0;
	start = find_start_end(dock, 1);
	end = find_start_end(dock, 2);
	while (i < count)
	{
		if (DOCK[start][i] == 1)
		{
			DOCK[start][i] = 2;
			j++;
		}
		if (DOCK[end][i] == 1)
		{
			DOCK[end][i] = 3;
			k++;
		}
		i++;
	}
	if (j == 0 || k == 0)
		return (0);
	copy_tab(dock, count, 0);
	return (1);
}

void		copy_tab(t_dock *dock, int count, int i)
{
	int		**tab;

	tab = DOCK;
	dock = DNEXT;
	while (DNEXT)
	{
		DOCK = (int **)malloc(sizeof(int *) * count);
		while (i < count)
		{
			DOCK[i] = (int *)malloc(sizeof(int) * count);
			i++;
		}
		i = 0;
		DOCK = tab;
		dock = DNEXT;
	}
	DOCK = tab;
}
