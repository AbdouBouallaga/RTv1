/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babdelka <babdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 21:42:11 by ahkhilad          #+#    #+#             */
/*   Updated: 2020/12/31 17:38:58 by babdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec	ft_lgt_computing(t_light *lgt, t_vec lgt_dir, t_hit *hit, t_ray *ray)
{
	t_vec	ambient;
	t_vec	color;
	t_vec	phong_dir;

	color = (t_vec){0.0f, 0.0f, 0.0f};
	lgt->ambient_strenght = 0.02f;
	ambient = ft_vectormulti(lgt->color, lgt->ambient_strenght);
	color.x = ambient.x * hit->object->color.x;
	color.y = ambient.y * hit->object->color.y;
	color.z = ambient.z * hit->object->color.z;
	lgt->lambert = fmax(0.0f, ft_dotproduct(lgt_dir, hit->n));
	color = ft_vectoradd(color, ft_vectormulti(hit->object->color,\
	lgt->lambert));
	lgt->reflect = 2.0f * (ft_dotproduct(lgt_dir, hit->n));
	phong_dir = ft_vectorsub(lgt_dir, ft_vectormulti(hit->n, lgt->reflect));
	lgt->phong_term = fmax(ft_dotproduct(phong_dir, ray->direction), 0.0f);
	lgt->phong_term = 1.0f * powf(lgt->phong_term, 90.0f) * 1.0f;
	color = ft_vectoradd(color, ft_vectormulti(lgt->color, lgt->phong_term));
	color.x = color.x * lgt->color.x * lgt->intensity;
	color.y = color.y * lgt->color.y * lgt->intensity;
	color.z = color.z * lgt->color.z * lgt->intensity;
	return (color);
}

void	shade(t_vec *color, t_hit *hit, t_light *light)
{
	t_vec		ambient;

	ambient = ft_vectormulti(light->color, 0.03f);
	color->x = color->x + ambient.x * hit->object->color.x;
	color->y = color->y + ambient.y * hit->object->color.y;
	color->z = color->z + ambient.z * hit->object->color.z;
}

int		ft_shade_object(t_hit *hit, t_light *lights, t_object *lst, t_ray *ray)
{
	t_light		*light;
	t_vec		color;
	t_vec		light_dir;
	t_ray		shadow_ray;
	float		t;

	color = (t_vec){0.0f, 0.0f, 0.0f};
	shadow_ray.source = hit->p;
	light = lights;
	while (light)
	{
		light_dir = ft_normalize(ft_vectorsub(light->pos, hit->p));
		shadow_ray.direction = light_dir;
		t = ft_magnitude(ft_vectorsub(light->pos, hit->p));
		if (!shadow_cast(lst, &shadow_ray, &t))
			color = ft_vectoradd(color, ft_lgt_computing(light, light_dir,\
		hit, ray));
		else
			shade(&color, hit, light);
		light = light->next;
	}
	return (rgb_to_int(clamp_vect(color)));
}

void	update(t_mx *mx)
{
	t_ray	ray;
	t_hit	hit;
	int		y;
	int		x;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			ray = camera_ray(&mx->cam, x, y);
			hit.t = INFINITY;
			if (raycast(mx->objects, &ray, &hit))
			{
				mx->rt[(WIN_H - 1 - y) * WIN_W + x] =\
					ft_shade_object(&hit, mx->lights, mx->objects, &ray);
			}
			x++;
		}
		y++;
	}
}

int		main(int ac, char **av)
{
	t_mx	v;

	if (ac == 2)
	{
		if (av[1])
		{
			ft_bzero(&v, sizeof(t_mx));
			if (!ft_open(av[1], &v))
			{
				ft_putstr("error! please try a valid configuration file.\n");
				exit(0);
			}
			else
				run(&v);
		}
	}
	else
		ft_usage();
	return (0);
}
