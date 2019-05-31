/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikovalen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 13:57:01 by ikovalen          #+#    #+#             */
/*   Updated: 2019/02/17 13:57:03 by ikovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		findroom(char *name, t_lem *lemin)
{
	int i;

	i = 0;
	while (lemin->rooms[i])
	{
		if (ft_strcmp(name, lemin->rooms[i]) == 0)
			return (i);
		i++;
	}
	i = 0;
	exit(ft_printf("ERROR: Wrong room\n"));
}

void	init(t_lem *lemin)
{
	lemin->comments = 0;
	lemin->startend = 0;
	lemin->checker = 0;
	lemin->rooms = (char **)malloc(BN * sizeof(char *));
	lemin->solve = 1;
	lemin->counter = 0;
	lemin->links = NULL;
	lemin->paths = NULL;
	lemin->index1 = 1;
	lemin->index2 = 0;
	lemin->index3 = 0;
	lemin->start = 0;
	lemin->end = 0;
	lemin->lines = 0;
}

int		main(void)
{
	MAINIT;
	while (get_next_line(0, &line) > 0 && ++lemin.comments)
	{
		if (line[0] == '#')
			checksharp(line, &lemin);
		else if (lemin.checker != 1)
			antsnum(line, &lemin);
		else if (ft_strchr(line, ' ') != NULL)
			addrooms(line, &lemin);
		else
			addlink(line, &lemin);
	}
	if (lemin.start && lemin.end && lemin.rooms && lemin.links)
		while (lemin.solve && !(lemin.solve = 0) && *lemin.links[lemin.end - 1])
			algo(&lemin);
	else
		exit(ft_printf("ERROR: No start/end/rooms/links!\n"));
	if (lemin.paths == NULL)
		exit(ft_printf("ERROR: No solution\n"));
	else
	{
		print_result(&lemin);
		ft_printf(GREEN"Number of lines: %i\n"EOM, lemin.lines);
	}
}
