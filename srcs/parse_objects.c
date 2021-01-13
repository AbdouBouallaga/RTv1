/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <ahkhilad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 18:11:31 by ahkhilad          #+#    #+#             */
/*   Updated: 2020/12/27 15:10:06 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int				ft_parse_sphere(t_mx *v, char **token)
{
	t_object	object;
	int			len;

	len = ft_strsplit_len(token);
	if (len == 6 && token)
		if (ft_check_vectors(token[1]) && ft_check_vectors(token[3])
				&& ft_check_vectors(token[4])
				&& ft_check_positive_floats(token[2])
				&& ft_check_hex_color(token[5]))
		{
			ft_bzero(&object, sizeof(t_object));
			object.type = SPHERE;
			tokenfill_sphere(token, &object);
			ft_object_push(&v->objects, ft_object_new(object));
		}
		else
			return (0);
	else
		return (0);
	return (1);
}

int				ft_parse_plane(t_mx *v, char **token)
{
	t_object	object;
	int			len;

	len = ft_strsplit_len(token);
	if (len == 6 && token)
	{
		if (ft_check_vectors(token[1]) && ft_check_directional_vec(token[2])
				&& ft_check_vectors(token[3]) && ft_check_vectors(token[4])
				&& ft_check_hex_color(token[5]))
		{
			ft_bzero(&object, sizeof(t_object));
			object.type = PLANE;
			tokenfill_plane(token, &object);
			ft_object_push(&v->objects, ft_object_new(object));
		}
		else
			return (0);
	}
	else
		return (0);
	return (1);
}

int				ft_parse_cone(t_mx *v, char **token)
{
	t_object	object;
	int			len;

	len = ft_strsplit_len(token);
	if (len == 7 && token)
	{
		if (ft_check_vectors(token[1]) && ft_check_directional_vec(token[3])
				&& ft_check_vectors(token[4]) && ft_check_vectors(token[5])
				&& ft_check_floats(token[2]) && ft_check_hex_color(token[6]))
		{
			ft_bzero(&object, sizeof(t_object));
			object.type = CONE;
			tokenfill_cone(token, &object);
			ft_object_push(&v->objects, ft_object_new(object));
		}
		else
			return (0);
	}
	else
		return (0);
	return (1);
}

int				ft_parse_cylinder(t_mx *v, char **token)
{
	t_object	object;
	int			len;

	len = ft_strsplit_len(token);
	if (len == 7 && token)
	{
		if (ft_check_vectors(token[1]) && ft_check_directional_vec(token[3])
				&& ft_check_vectors(token[4]) && ft_check_vectors(token[5])
				&& ft_check_positive_floats(token[2])
				&& ft_check_hex_color(token[6]))
		{
			ft_bzero(&object, sizeof(t_object));
			object.type = CYLINDER;
			tokenfill_cylinder(token, &object);
			ft_object_push(&v->objects, ft_object_new(object));
		}
		else
			return (0);
	}
	else
		return (0);
	return (1);
}

int				ft_parse_light(t_mx *v, char **token)
{
	t_light		light;
	int			len;

	len = ft_strsplit_len(token);
	if (len == 4 && token)
		if (ft_check_vectors(token[1]) && ft_check_positive_floats(token[2])
				&& ft_check_hex_color(token[3]))
		{
			ft_bzero(&light, sizeof(t_light));
			if (token[1])
				light.pos = string_to_vect(token[1]);
			if (token[2])
			{
				light.intensity = ft_atof(token[2]);
			}
			if (token[3])
				light.color = vect_from_hexa(ft_special_atoi_base(token[3]));
			ft_light_push(&v->lights, \
			ft_light_new(light.pos, light.color, light.intensity));
		}
		else
			return (0);
	else
		return (0);
	return (1);
}
