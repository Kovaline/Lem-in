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
		while (++j < k && (i = *lemin->paths[j] + 1))
			while (--i)
				if ((i > 1 && (lemin->print[j][i] = lemin->print[j][i - 1])) ||
					(i == 1 && *lemin->print[j] && (*lemin->print[j])-- &&
					++lemin->index3 && (lemin->print[j][1] = lemin->index3)) ||
					(i == 1 && (lemin->print[j][1] = 0)))
				{
					lemin->index1 = ft_printf("L%i-%s", lemin->print[j][i],
						lemin->rooms[lemin->paths[j][i] - 1]);
					if (i != 1)
						ft_printf(" ");
				}
		if (lemin->index1 != 0)
		{	
			lemin->lines++;
			ft_printf("\n");
		}
	}
}

int		countpaths(t_lem *lemin)
{
	int i;

	i = 0;
	while (lemin->paths[i])
		i++;
	return (i);
}

void	print_result(t_lem *lemin)
{
	INIT;
	j = countpaths(lemin);
	PR;
	while (lemin->paths[++k])
		lemin->print[k] = (int*)ft_memalloc((*lemin->paths[k] + 2) * 4);
	while (--i >= 0 && ++**lemin->print && !(k = 0))
		while (++k < j)
			if (*lemin->print[k - 1] + *lemin->paths[k - 1] >
				*lemin->print[k] + *lemin->paths[k] && i--)
				++*lemin->print[k];
	print(lemin, j);
}
