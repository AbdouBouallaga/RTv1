/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babdelka <babdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 18:13:28 by ahkhilad          #+#    #+#             */
/*   Updated: 2020/12/29 08:42:40 by babdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec		ft_rotate_object(t_vec to_rot, t_vec rot, int invert)
{
	if (invert)
	{
		to_rot = z_rotation(to_rot, -rot.z);
		to_rot = y_rotation(to_rot, -rot.y);
		to_rot = x_rotation(to_rot, -rot.x);
	}
	else
	{
		to_rot = x_rotation(to_rot, rot.x);
		to_rot = y_rotation(to_rot, rot.y);
		to_rot = z_rotation(to_rot, rot.z);
	}
	return (to_rot);
}

t_vec		ft_translate_object(t_vec to_trans, t_vec trans, int invert)
{
	t_vec	result;

	if (invert)
	{
		result.x = to_trans.x - trans.x;
		result.y = to_trans.y - trans.y;
		result.z = to_trans.z - trans.z;
	}
	else
	{
		result.x = to_trans.x + trans.x;
		result.y = to_trans.y + trans.y;
		result.z = to_trans.z + trans.z;
	}
	return (result);
}

t_ray		ft_transform_ray(t_object *obj, t_ray *raw, int invert)
{
	t_ray	result;

	result = *raw;
	result.source = ft_rotate_object(raw->source, obj->rot, invert);
	result.source = ft_translate_object(result.source, obj->trans, invert);
	result.direction = ft_rotate_object(raw->direction, obj->rot, invert);
	return (result);
}

float		clamp(float value, float min, float max)
{
	if (value < min)
	{
		value = min;
	}
	else if (value > max)
	{
		value = max;
	}
	return (value);
}

t_vec		clamp_vect(t_vec v)
{
	v.x = clamp(v.x * 255, 0.0f, 255.0f);
	v.y = clamp(v.y * 255, 0.0f, 255.0f);
	v.z = clamp(v.z * 255, 0.0f, 255.0f);
	return (v);
}
