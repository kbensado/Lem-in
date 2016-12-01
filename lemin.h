/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 03:54:40 by kbensado          #+#    #+#             */
/*   Updated: 2016/05/10 03:54:41 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "ft_printf/includes/ft_printf.h"
# define BUFF_SIZE 1
# define NUM ft_str_is_numericable
# define MAP list->map
# define LEND list->end
# define LSTART list->start
# define CHECK list->check
# define ROOM list->room
# define RO list->room
# define NROOM list->n_room
# define NA list->nb_ants
# define NAME dock->name
# define KEY dock->key
# define DOCK dock->map
# define NROOM2 dock->n_room
# define DNEXT dock->next
# define A dock->coord_a
# define B dock->coord_b
# define POS dock->pos
# define ANTS dock->ants
# define PATH path->tab
# define NPATH path->next
# define LEN path->len
# define END path->end
# define HILE hile[len_tab(tab, NROOM2, 0) - 1]
# define COUNT len_tab(tab, NROOM2, 0)
# define FIND find_start_end(dock, 2)
# define BB ft_strchr(MAP[i + 1], '-')
# define AA ft_strstr(MAP[i + 1], "##")
# define CC (ft_atol(MAP[0]) > -2147483648) && (ft_atol(MAP[0]) < 2147483647)
# define DD ft_strcmp("##end", MAP[i - 1]) == 0
# define FF tab[i - 1] != find_start_end(dock, 2)
# define GG ft_strcmp(ROOM[0], "##start") && ft_strcmp(ROOM[0], "##end")
# define HH ft_strstr(MAP[i + 1], "##end") || ft_strstr(MAP[i + 1], "##start")

typedef struct		s_path
{
	int				nb_room;
	int				len;
	int				*tab;
	int				end;
	struct s_path	*next;

}					t_path;

typedef struct		s_ants
{
	char			**map;
	char			**room;
	int				nb_ants;
	int				nb_line;
	int				check;
	int				start;
	int				end;
	int				index;
	int				n_room;

}					t_ants;

typedef struct		s_dock
{
	int				index;
	int				ants;
	int				pos;
	int				key;
	int				len;
	int				count;
	int				last;
	int				n_room;
	int				n_ants;
	int				coord_a;
	int				coord_b;
	char			**room;
	char			*name;
	int				**map;
	struct s_dock	*next;

}					t_dock;

int					main(void);
int					*set_tab(int *tab, int nb);
int					ft_tabcmp(int *tab, int *tab2, int count);
int					*ft_tabdup(int	*tab, int count);
char				*get_name(t_dock *dock, int key);
int					free_path(t_path **begin_list);
double				ft_catoi(const char *str);
char				**fu(char **map);
void				free_ants(t_ants **begin_list);
void				free_dock(t_dock **begin_list);
int					*set_next(int *tab, int i, int count);
int					*get_low(t_path *path, t_dock *dock);
int					*catch_it(int *tab, int end, int i, int index);
int					len_tab(int *tab, int nb, int check);
int					ft_nbrchr(int *tab, int target, int index);
int					agent_of_chaos(t_dock *dock, t_path *path);
int					move(t_path *path, t_dock *dock, int i, int *tab);
void				ft_path_push_front(t_path **begin_list,
	int *tab, int nb, int end);
t_path				*ft_create_path(int *tab, int nb, int end);
int					riset_matrice(t_dock *dock, int i, int count, int j);
int					*find_path(t_dock *dock, int *tab, int start, t_path *path);
int					do_it(t_dock *dock, int i, int *tab, t_path *path);
int					get_nbants(t_dock *dock, int i);
int					find_start_end(t_dock *dock, int i);
int					no_else(t_path *path, int *tab, int i);
void				check_tab(int **tab, int count);
void				copy_tab(t_dock *dock, int count, int i);
int					found_key(t_dock *dock, char *room);
int					**set_double_tab(int count, int i, int j);
void				check_path_list(t_path *path);
int					link_them(t_ants *list, t_dock *dock, int j, int i);
void				check_room(t_dock *dock);
int					ft_list_size(t_dock *list, int nb, t_path *path);
int					riset_matrice(t_dock *dock, int i, int count, int j);
void				free_tab(int **tab, int i);
int					why_so_serious(t_dock *dock, t_ants *list);
int					free_list_path(t_path *path);
int					**set_matrice(t_dock *dock, char **str);
t_ants				*init_ants(t_ants *list);
int					is_possible(t_dock *dock, int i, int j, t_ants *list);
int					ft_str_is_numericable(char *str);
t_dock				*get_dock(t_ants *list, int i, int j, t_dock *dock);
int					get_ants(t_ants *list, t_dock *dock, int i);
char				**get_stdin(t_ants *list, int i, int j, char *line);
void				free_list(t_ants *list, int i, t_dock *dock);
void				free_char(char **str, int i);
void				ft_dock_push_back(t_dock **begin_list, t_ants *data, int j);
t_dock				*ft_create_dock(t_ants *list, int j, t_dock *dock);

#endif
