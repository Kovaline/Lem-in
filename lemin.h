/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikovalen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 13:57:10 by ikovalen          #+#    #+#             */
/*   Updated: 2019/05/31 15:32:21 by ikovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# define INIT int i; int j
# define PR int k;k=-1;lemin->print = (int**)ft_newintarr(j,0,0);i=lemin->ants
# define BN 100000
# define MAINIT char *line;t_lem lemin;init(&lemin)
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
	int 			lines;
}					t_lem;

void				addlink(char *line, t_lem *lemin);
void				addrooms(char *line, t_lem *lemin);
void				antsnum(char *line, t_lem *lemin);
void				checksharp(char *line, t_lem *lemin);
int					findroom(char *name, t_lem *lemin);
void				algo(t_lem *lemin);
void				print_result(t_lem *lemin);

#endif
