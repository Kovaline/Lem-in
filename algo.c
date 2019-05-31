/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikovalen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 13:29:15 by ikovalen          #+#    #+#             */
/*   Updated: 2019/05/27 13:29:17 by ikovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	algo2(t_lem *lemin, int i, int j)
{
	while (!lemin->solve && j != 1)
	{
		j--;
		if (!lemin->path[lemin->links[i - 1][j]] &&
			(lemin->path[lemin->links[i - 1][j]] = *lemin->path) &&
			++lemin->going && lemin->links[i - 1][j] == lemin->end)
			lemin->solve = 1;
	}
}

void	continuealgo2(t_lem *lemin)
{
	INIT;
	while (--*lemin->path)
	{
		i = 0;
		while (!lemin->ways[*lemin->path] && ++i <= lemin->counter)
		{
			if (lemin->path[i] == *lemin->path + 1)
			{
				j = 0;
				while (!lemin->ways[*lemin->path] &&
					++j <= *lemin->links[i - 1])
					if (lemin->links[i - 1][j] == lemin->ways[*lemin->path + 1])
						lemin->ways[*lemin->path] = i;
			}
		}
	}
}

void	initalgo(t_lem *lemin)
{
	lemin->path = ft_memalloc((1 + lemin->counter + 1) * 4);
	*lemin->path = 1;
	lemin->path[lemin->start] = *lemin->path;
	lemin->going = 1;
}

void	continuealgo(t_lem *lemin)
{
	int i;

	i = 0;
	lemin->ways = ft_memalloc((*lemin->path + 1) * 4);
	*lemin->ways = --*lemin->path;
	lemin->ways[*lemin->path] = lemin->end;
	continuealgo2(lemin);
	while (++i < *lemin->ways)
		*lemin->links[lemin->ways[i] - 1] = 0;
	lemin->paths = (int**)ft_arradd((void***)&lemin->paths,
		(void**)&lemin->ways);
	free(lemin->ways);
}

void	algo(t_lem *lemin)
{
	INIT;
	initalgo(lemin);
	while (!lemin->solve && lemin->going &&
		!(lemin->going = 0) && ++*lemin->path)
	{
		i = 0;
		while (!lemin->solve && ++i <= lemin->counter)
			if (lemin->path[i] == *lemin->path - 1
					&& (j = *lemin->links[i - 1] + (1)))
				algo2(lemin, i, j);
	}
	if (lemin->solve && --*lemin->links[lemin->end - 1] >= 0)
		continuealgo(lemin);
	free(lemin->path);
}
