/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 22:33:27 by kbensado          #+#    #+#             */
/*   Updated: 2016/02/14 22:33:36 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				count_line(char *tmp, unsigned int i)
{
	while (tmp[i] != '\n' && tmp[i] != '\0')
		i++;
	return (i);
}

int				get_next_line(int fd, char **file)
{
	int			r;
	static char	*t;
	char		buff[BUFF_SIZE + 1];

	if (fd < 0 || read(fd, buff, 0) < 0)
		return (-1);
	if (t == NULL)
		t = ft_strnew(1);
	while (!(ft_strchr(t, '\n')) && (r = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[r] = '\0';
		t = ft_strjoin(t, buff);
	}
	*file = ft_strsub(t, 0, count_line(t, 0));
	if (ft_strchr(t, '\n'))
	{
		t = ft_strchr(t, '\n') + 1;
		return (1);
	}
	if (count_line(t, 0))
	{
		t = t + count_line(t, 0);
		return (1);
	}
	return (r ? 1 : 0);
}
