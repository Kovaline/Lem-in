/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikovalen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 14:01:04 by ikovalen          #+#    #+#             */
/*   Updated: 2019/05/29 14:01:16 by ikovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	print(t_lem *lemin, int k)
{
	INIT;
	while (lemin->index1 && ++lemin->index2)
	{
		j = -1;
		lemin->index1 = 0;
		while (++j < k && !(lemin->prcount = 0))
		{
			i = *lemin->paths[j] + 1;
			while (--i)
				if ((i > 1 && (lemin->print[j][i] = lemin->print[j][i - 1])) ||
					(i == 1 && *lemin->print[j] && (*lemin->print[j])-- &&
					++lemin->index3 && (lemin->print[j][1] = lemin->index3)) ||
					(i == 1 && (lemin->print[j][1] = 0)))
				{
					if (lemin->prcount++ != 0 ||
						(lemin->counter == 2 && lemin->count2++ != 0))
						ft_printf(" ");
					lemin->index1 = ft_printf("L%i-%s", lemin->print[j][i],
						lemin->rooms[lemin->paths[j][i] - 1]);
				}
		}
		if (lemin->counter != 2 && lemin->index1 != 0 && lemin->lines++)
			ft_printf("\n");
	}
}

void	print_result(t_lem *lemin)
{
	INIT;
	K;
	j = countpaths(lemin);
	lemin->print = (int**)ft_newintarr(j, 0, 0);
	i = lemin->ants;
	while (lemin->paths[++k])
		lemin->print[k] = (int*)ft_memalloc((*lemin->paths[k] + 2) * 4);
	while (--i >= 0 && ++**lemin->print && !(k = 0))
		while (++k < j)
			if (*lemin->print[k - 1] + *lemin->paths[k - 1] >
				*lemin->print[k] + *lemin->paths[k] && i--)
				++*lemin->print[k];
	print(lemin, j);
}

void	printing(t_lem *lemin, char **argv)
{
	flags(lemin, argv);
	if (!lemin->nomap)
	{
		display_map(g_info);
		write(1, "\n", 1);
	}
	print_result(lemin);
	if (lemin->counter == 2)
		ft_printf("\n");
	if (lemin->lin)
		ft_printf(GREEN"Number of lines: %i\n"EOM, lemin->lines - 1);
	if (lemin->leaks)
		system("leaks lem-in");
}
