/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikovalen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 14:57:36 by ikovalen          #+#    #+#             */
/*   Updated: 2019/06/03 14:57:37 by ikovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		countpaths(t_lem *lemin)
{
	int i;

	i = 0;
	while (lemin->paths[i])
		i++;
	return (i);
}

void	display_map(t_list *list)
{
	if (list)
	{
		display_map(list->next);
		write(1, list->content, ft_strlen(list->content));
		write(1, "\n", 1);
	}
}

void	flags(t_lem *lemin, char **argv)
{
	int i;

	i = 1;
	while (argv[i])
	{
		if (!ft_strcmp(argv[i], "-nomap"))
			lemin->nomap++;
		else if (!ft_strcmp(argv[i], "-leaks"))
			lemin->leaks++;
		else if (!ft_strcmp(argv[i], "-lines"))
			lemin->lin++;
		else
		{
			ft_printf("WRONG FLAG\n\nusage: ./lem-in [flags] < [map]\n");
			ft_printf("-nomap : Do not print map\n-leaks : Print leaks info");
			exit(ft_printf("\n-lines : Print number of lines\n"));
		}
		i++;
	}
}
