/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 17:11:43 by kbensado          #+#    #+#             */
/*   Updated: 2016/04/13 17:11:44 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int		gtfo(void)
{
	WS("ERROR");
	return (0);
}

static int		launch_lemin(t_ants *list, t_dock *dock)
{
	if (!(list = init_ants(list)))
		return (gtfo());
	if (!(MAP = get_stdin(list, 0, 0, ft_strnew(1))))
		return (gtfo());
	if (MAP[5] == NULL)
		return (gtfo());
	if (!(get_ants(list, dock, 0)))
		return (gtfo());
	return (1);
}

int				main(void)
{
	t_ants		*list;
	t_dock		*dock;

	list = NULL;
	dock = NULL;
	if (!(launch_lemin(list, dock)))
		return (0);
	return (0);
}
