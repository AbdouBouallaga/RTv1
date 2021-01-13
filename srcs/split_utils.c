/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babdelka <babdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 17:37:19 by ahkhilad          #+#    #+#             */
/*   Updated: 2020/12/30 18:33:19 by babdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

char		*ft_strcmptable(const char *str, char **tab)
{
	while (*tab && !ft_strequ(str, *tab))
	{
		tab++;
	}
	return (*tab);
}

void		ft_strsplit_free(char ***tab)
{
	int		i;

	i = -1;
	while ((*tab)[++i])
		free((*tab)[i]);
	free((*tab));
}

int			ft_strsplit_len(char **tab)
{
	int		i;

	i = -1;
	while (tab[++i])
		;
	return (i);
}
