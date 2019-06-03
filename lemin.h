/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikovalen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 13:57:10 by ikovalen          #+#    #+#             */
/*   Updated: 2019/06/03 16:01:11 by ikovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# define INIT int i; int j
# define K int k=-1
# define BN 100000
# include "ft_printf/ft_printf.h"

typedef struct		s_lem
{
	int				comments;
	char			startend;
	int				*path;
	int				**paths;
	int				**links;
	int				ants;
	int				counter;
	int				start;
	int				end;
	char			**rooms;
	int				checker;
	int				link;
	int				solve;
	int				going;
	int				*ways;
	int				**print;
	int				index1;
	int				index2;
	int				index3;
	int				prcount;
	int				lines;
	int				nomap;
	int				argc;
	int				leaks;
	int				lin;
	int				count2;
	int				printpaths;
}					t_lem;

extern t_list			*g_info;

void				addlink(char *line, t_lem *lemin);
void				addrooms(char *line, t_lem *lemin);
void				antsnum(char *line, t_lem *lemin);
void				checksharp(char *line, t_lem *lemin);
int					findroom(char *name, t_lem *lemin);
void				algo(t_lem *lemin);
void				print_result(t_lem *lemin);
void				printing(t_lem *lemin, char **argv);
int					countpaths(t_lem *lemin);
void				display_map(t_list *list);
void				flags(t_lem *lemin, char **argv);

#endif
