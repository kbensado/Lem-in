/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 21:48:57 by kbensado          #+#    #+#             */
/*   Updated: 2016/04/15 21:48:59 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			ft_str_is_numericable(char *str)
{
	int		i;

	i = 0;
	if (str[i])
	{
		while (str[i])
		{
			if (str[i] >= '0' && str[i] <= '9')
				i++;
			else
				return (0);
		}
		return (1);
	}
	return (0);
}

void		free_char(char **str, int i)
{
	if (str)
	{
		while (str[i] != NULL)
		{
			free(str[i]);
			str[i] = NULL;
			i++;
		}
	}
}

int			**set_double_tab(int count, int i, int j)
{
	int		**tmp;

	count++;
	tmp = (int **)malloc(sizeof(int *) * count);
	while (i < count)
		tmp[i++] = (int *)malloc(sizeof(int) * count);
	i = 0;
	if (tmp)
	{
		while (i < count)
		{
			j++;
			if (j == count)
			{
				i++;
				j = 0;
			}
		}
		return (tmp);
	}
	return (NULL);
}

void		free_tab(int **tab, int i)
{
	int		j;

	j = 0;
	while (j < i)
	{
		free(tab[j]);
		j++;
	}
}

int			**set_matrice(t_dock *dock, char **str)
{
	DOCK[found_key(dock, str[0])][found_key(dock, str[1])] = 1;
	DOCK[found_key(dock, str[1])][found_key(dock, str[0])] = 1;
	return (DOCK);
}
