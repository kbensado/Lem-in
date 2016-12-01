/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   joker.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 08:01:24 by kbensado          #+#    #+#             */
/*   Updated: 2016/05/14 08:01:26 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

char		**fu(char **map)
{
	if (map == NULL)
		return (0);
	if (ft_catoi(map[0]) == 0)
		return (0);
	return (map);
}

int			why_so_serious(t_dock *dock, t_ants *list)
{
	int		i;
	int		nb;

	nb = NA;
	i = 0;
	if (KEY != 1)
		dock = DNEXT;
	while (MAP[i])
		WS(MAP[i++]);
	ft_putchar('\n');
	i = 0;
	while (i++ < nb)
		ft_printf("L%d-%s ", i, NAME);
	ft_putchar('\n');
	free_dock(&dock);
	free_ants(&list);
	return (1);
}

int			agent_of_chaos(t_dock *dock, t_path *path)
{
	int		i;
	int		ants;

	ants = get_nbants(dock, 1);
	i = 0;
	while (dock->room[i])
		WS(dock->room[i++]);
	if (POS != 2)
		dock = DNEXT;
	ft_putchar('\n');
	i = 0;
	while (i++ < ants)
		ft_printf("L%d-%s ", i, NAME);
	ft_putchar('\n');
	return (free_path(&path));
}

double		ft_catoi(const char *str)
{
	int		nb;
	int		i;

	i = 0;
	nb = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\r' || str[i] == '\f' || str[i] == '\v')
		i++;
	if (str[i] == '+')
		i++;
	if (str[i] == '-')
		return (0);
	while (str[i] && str[i] <= '9' && str[i] >= '0')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	if (i > 10 || nb < 0 || nb > 2147483647)
		return (0);
	return (nb);
}
