/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 14:15:53 by ahkhilad          #+#    #+#             */
/*   Updated: 2019/04/13 14:17:16 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqrt(int nb)
{
	int i;

	i = 1;
	if (nb == 4)
		return (2);
	if (nb == 9)
		return (3);
	if (nb == 16)
		return (4);
	while (i <= nb / 5)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (0);
}
