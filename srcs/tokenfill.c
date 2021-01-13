/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <ahkhilad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 18:54:28 by babdelka          #+#    #+#             */
/*   Updated: 2020/12/29 08:24:15 by babdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	tokenfill_sphere(char **token, t_object *object)
{
	if (token[1])
		object->pos = string_to_vect(token[1]);
	if (token[2])
		object->radius = ft_atof(token[2]);
	if (token[3])
		object->rot = string_to_vect(token[3]);
	if (token[4])
		object->trans = string_to_vect(token[4]);
	if (token[5])
		object->color = vect_from_hexa(ft_special_atoi_base(token[5]));
}

void	tokenfill_plane(char **token, t_object *object)
{
	if (token[1])
		object->pos = string_to_vect(token[1]);
	if (token[2])
		object->normal = string_to_vect(token[2]);
	if (token[3])
		object->rot = string_to_vect(token[3]);
	if (token[4])
		object->trans = string_to_vect(token[4]);
	if (token[5])
		object->color = vect_from_hexa(ft_special_atoi_base(token[5]));
}

void	tokenfill_cone(char **token, t_object *object)
{
	if (token[1])
		object->pos = string_to_vect(token[1]);
	if (token[2])
		object->angle = ft_atof(token[2]);
	if (token[3])
		object->axis = string_to_vect(token[3]);
	if (token[4])
		object->rot = string_to_vect(token[4]);
	if (token[5])
		object->trans = string_to_vect(token[5]);
	if (token[6])
		object->color = vect_from_hexa(ft_special_atoi_base(token[6]));
}

void	tokenfill_cylinder(char **token, t_object *object)
{
	if (token[1])
		object->pos = string_to_vect(token[1]);
	if (token[2])
		object->radius = ft_atof(token[2]);
	if (token[3])
		object->axis = string_to_vect(token[3]);
	if (token[4])
		object->rot = string_to_vect(token[4]);
	if (token[5])
		object->trans = string_to_vect(token[5]);
	if (token[6])
		object->color = vect_from_hexa(ft_special_atoi_base(token[6]));
}
