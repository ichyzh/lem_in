/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichyzh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 18:47:17 by ichyzh            #+#    #+#             */
/*   Updated: 2018/06/10 18:47:19 by ichyzh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_H
# define LEM_H
# include "libft/includes/libft.h"

typedef struct			s_room
{
	int					x;
	int					y;
	char				*name;
	int					s_e;
	int					pos;
	struct s_room		*next;
}						t_room;

typedef struct			s_route
{
	int					ants;
	int					vis;
	char				*name;
	int					count;
	int					s_e;
	struct s_route		*next;
	struct s_route		*next_route;
}						t_route;

typedef struct			s_ant
{
	int					ants;
	int					number;
	int					moves;
	struct s_ant		*next;
	struct s_route		*route;
}						t_ant;

typedef struct			s_adjlist
{
	char				*name;
	int					pos;
	struct s_adjlist	*next;
}						t_adjlist;

typedef struct			s_que
{
	char				*name;
	int					s_e;
	int					pos;
	int					vis;
	struct s_que		*prev;
	struct s_que		*next;
}						t_que;

typedef struct			s_graph
{
	struct s_adjlist	**node;
}						t_graph;

typedef struct			s_lemin
{
	char				*data;
	struct s_room		*room;
	struct s_route		*route;
	struct s_ant		*ant;
	struct s_adjlist	*adj;
	struct s_que		*que;
	struct s_graph		*gra;
}						t_lem;

void					save_data(t_lem **lem, char *line);
void					print_error(t_lem **lem, int i);
void					ft_lemin(t_lem **lem);
void					init_lemin(t_lem **lem);
int						find_dup_room(char **s, t_room **room);
void					create_ant_list(t_ant *ant);
t_ant					*create_ant_node(int n);
void					add_ant_node(t_ant *ant, t_ant *temp);
int						check_ants(t_lem **lem);
void					drop_comments(t_lem **lem, char **line);
void					ft_clear_arr(char **arr);
void					check_start_end(t_lem **lem, char **str);
void					add_start_end(t_lem **lem, char **str, int i);
void					check_room(t_lem **lem, char **line);
t_room					*create_room(char **str, int s);
int						valid_room(char *str, t_room **room);
int						only_number(char *str);
int						corect_room(t_room *room);
int						ft_listlen(t_room **room);
int						check_pos_node(t_room **room, char *str);
int						find_start(t_room *room);
void					check_link(char **str, t_lem **lem);
int						add_link(char **str, t_lem **lem);
t_graph					*create_graph(int len);
t_adjlist				*create_node(char *name, int pos);
void					add_edge(t_graph *graph, char *v1,
						char *v2, t_room **room);
void					create_path(t_lem **lem, t_que **temp, int curr, int p);
void					check_path(t_lem **lem);
int						find_same(t_que *que, t_adjlist *node, t_que *prev);
void					ft_lst_push_back(t_room **begin_list, t_room *temp);
int						val_link(char *str, t_room **room);
t_que					*create_que(t_room *room, int p, int s);
t_que					*create_q_node(char *str, int p, int s);
void					add_in_queue(t_que *cur, t_que **q, t_que *prev);
int						check_root(t_que *q);
int						check_prev(t_que *prev, t_adjlist *node, t_que *que);
int						is_start_end(t_room *room, int pos);
void					create_route(t_que **que, t_route **route);
t_route					*create_r_node(char *str, int i, int s_e);
t_route					*add_to_route(t_route **route, t_que *tmp, int i);
int						check_same_in_r(char *str, t_route *route);
void					count_ants(int ants, t_route **head,
						t_route *route);
void					add_route_to_ant(t_route **head,
						t_route *route, t_ant **ant, int ants);
void					move_ant(t_ant **ant, t_ant *temp);
void					print_ant(t_ant *temp);
void					dequeue(t_que **temp, t_route *route);
void					place_one_route(t_route **head, t_ant **ant);
int						find_one_route(t_route **route);
int						node_root(t_que *prev, t_adjlist *node, t_que *que);
int						same_root(t_que *prev, t_adjlist *node, t_que *que);
t_que					*ret_prev_node(int pos, t_que *route, t_que *prev);
void					work_with_path(t_lem **lem);

#endif
