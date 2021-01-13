/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_negative.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <ahkhilad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:52:49 by ahkhilad          #+#    #+#             */
/*   Updated: 2020/07/01 03:01:57 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linear_alg.h"

t_vec		ft_negative(t_vec v)
{
	t_vec	c;

	c.x = -1.0 * v.x;
	c.y = -1.0 * v.y;
	c.z = -1.0 * v.z;
	return (c);
}
