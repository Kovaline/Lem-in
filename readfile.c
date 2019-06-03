/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikovalen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 16:49:02 by ikovalen          #+#    #+#             */
/*   Updated: 2019/05/31 15:32:46 by ikovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	addlink(char *line, t_lem *lemin)
{
	char **str;

	INIT;
	if (lemin->links == NULL)
		lemin->links = (int**)ft_newintarr(lemin->counter + 1,
			lemin->counter + 1, 32);
	str = ft_strsplit(line, '-');
	i = findroom(str[0], lemin);
	j = findroom(str[1], lemin);
	++*lemin->links[i];
	lemin->links[i][*lemin->links[i]] = j + 1;
	++*lemin->links[j];
	lemin->links[j][*lemin->links[j]] = i + 1;
	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	addrooms(char *line, t_lem *lemin)
{
	char	**str;
	int		i;

	i = 0;
	if (lemin->links != NULL)
		exit(ft_printf("ERROR: Rooms after links are forbidden\n"));
	str = ft_strsplit(line, ' ');
	if (str[3] != '\0' || str[2] == '\0' || str[1] == '\0' || str[0] == '\0')
		exit(ft_printf("ERROR: Invalid rooms\n"));
	while (str[2][i] && ft_isdigit(str[2][i]))
		i++;
	if ((i = 0) && str[2][i] != '\0')
		exit(ft_printf("ERROR: Wrong coordinates\n"));
	while (str[1][i] && ft_isdigit(str[1][i]))
		i++;
	if (str[1][i] != '\0')
		exit(ft_printf("ERROR: Wrong coordinates\n"));
	if (str[0][0] == 'L' || str[0][0] == '#')
		exit(ft_printf("ERROR: Rooms cant be named with L or #\n"));
	lemin->rooms[lemin->counter++] = ft_strdup(str[0]);
	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	antsnum(char *line, t_lem *lemin)
{
	int i;

	i = 0;
	while (line[i] != '\0' && ft_isdigit(line[i]))
		i++;
	if (line[i] != '\0')
		exit(ft_printf("ERROR: Only digits allowed for number of ants\n"));
	lemin->ants = ft_atoi(line);
	if (lemin->ants < 1)
		exit(ft_printf("ERROR: Negative number of ants\n"));
	lemin->checker = 1;
}

void	checksharp(char *line, t_lem *lemin)
{
	if (ft_strcmp(line, "##start") == 0)
	{
		lemin->start = lemin->comments - ++lemin->startend;
	}
	else if (ft_strcmp(line, "##end") == 0)
	{
		lemin->end = lemin->comments - ++lemin->startend;
	}
	else
	{
		lemin->comments--;
	}
}
