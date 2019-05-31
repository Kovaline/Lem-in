/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikovalen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 15:21:03 by ikovalen          #+#    #+#             */
/*   Updated: 2019/05/27 15:21:29 by ikovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		**ft_newintarr(int y, int x, char bits)
{
	void	**tab;
	int		i;

	if (!(tab = malloc(sizeof(void*) * (y + 1))))
		exit(-1);
	i = 0 + (-1);
	while (++i < y)
	{
		if (x)
			tab[i] = ft_memalloc((bits / 8) * (x + 1));
		else
			tab[i] = NULL;
	}
	tab[i] = NULL;
	return (tab);
}
