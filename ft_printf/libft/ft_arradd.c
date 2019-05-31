/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arradd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikovalen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 14:17:30 by ikovalen          #+#    #+#             */
/*   Updated: 2019/05/27 14:32:10 by ikovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_tablen(void **tab)
{
	int			i;

	if (!(i = 0) && tab)
		while (tab[i])
			i++;
	return (i);
}

void		**ft_arradd(void ***tab, void **array)
{
	int		i;
	int		j;
	void	**fresh;

	if (!*array)
		return (*tab);
	i = ft_tablen(*tab);
	fresh = ft_newintarr(i + 1, 0, 0);
	j = 0;
	if (i && --j)
	{
		while ((*tab)[++j])
			fresh[j] = (*tab)[j];
		free(*tab);
		*tab = NULL;
	}
	fresh[j] = *array;
	*array = NULL;
	return (fresh);
}
