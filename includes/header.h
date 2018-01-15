/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skgatle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 05:28:48 by skgatle           #+#    #+#             */
/*   Updated: 2017/12/08 05:28:54 by skgatle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEMIN_H
# define FT_LEMIN_H

# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
//# include <libc.h>
# include <stdlib.h>

typedef struct			s_connect
{
	struct s_connect	*next;
	struct s_room		*room;
}						t_connect;

typedef struct		s_backpack
{
	struct s_backpack	*next;
	char				*id;
	int					st_end;
}					t_backpack;

typedef struct		s_routes
{
	struct s_backpack	*route;
	struct s_routes		*next;
	struct s_routes		*compatable;
	struct s_routes		*checking;
	int					taken;
}					t_routes;

typedef struct		s_best
{
	int				len_tot;
	struct s_routes	*routes;
	int				num_routes;
}					t_best;

typedef struct		s_best_route
{
	t_backpack			*route;
	struct s_best_route	*next;
	int					route_len;
}					t_best_route;

typedef struct		s_room
{
	struct s_room	*next;
	char			*id;
	char			*posx;
	char			*posy;
	int				is_start;
	int				is_end;
	int				num_of_ants;
	t_connect			*connect;
	t_connect			*start_connections;
	t_backpack			*backpack;
	int					routes_needed;
	t_routes			*routes;
}						t_room;

typedef struct			s_lemmin
{
	char				*name;
	struct s_lemmin		*next;
	t_room				*room;
	t_backpack			*route;
	int					moves;
}						t_lemmin;

t_room					*ft_process_file();
void					display_map(t_room **room);
void					ft_error_handler(size_t err_no, char ext);
void					ft_add_to_room_end(t_room **start, t_room *new_room);
int						ft_connect_edges(t_room **room, char **line);
void					ft_add_connections_end(t_connect **start, t_room *new_room);
void					init_routes(t_room **room);
void					process_routes_needed(t_room **room);
void					start_connections(t_room **room);
t_room					*return_start(t_room **room);
t_room					*return_end(t_room **room);
void					ft_move_lem(t_room *room, t_backpack *backpack);
void					ft_move_lemmins(t_room **rooms, t_best_route *best, t_lemmin *lemmin);
void					ft_find_no_conflicts(t_routes **start);
t_best					*ft_find_best(t_routes **start);
void					ft_simulate(t_room **rooms, t_best *best);
t_lemmin				*ft_create_lemmins(t_room **rooms);
int						check_char(char **line, char c);
int						check_num(char *str);
t_room					*new_room(char **input, int start_end, int num_of_ants);
int						find_char(char **line, char c);
int						array2d_len(char **arr);
#endif
