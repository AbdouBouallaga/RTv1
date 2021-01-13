/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babdelka <babdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 18:07:49 by ahkhilad          #+#    #+#             */
/*   Updated: 2020/12/31 12:34:55 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		ft_usage(void)
{
	ft_putstr("Usage: binary file [a valid configuration file].\n");
	exit(0);
}

int			key_press(int keycode, void *p)
{
	t_mx	*v;

	v = (t_mx *)p;
	if (keycode == 53)
	{
		ft_destroy(v);
		exit(0);
	}
	return (0);
}

int			red_button(void *p)
{
	t_mx	*v;

	v = (t_mx *)p;
	ft_destroy(v);
	exit(0);
}

void		run(t_mx *mx)
{
	setup(mx);
	update(mx);
	display(mx);
}
