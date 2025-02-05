/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:55:25 by fstaryk           #+#    #+#             */
/*   Updated: 2023/01/24 14:59:33 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_p3	ray_reflect(t_p3 dir, t_p3 normal)
{
	return (_substruct(_multy(normal, 2 * _dot(normal, dir)), dir));
}

t_p3	ray_refraction(t_p3 dir, t_p3 normal, t_figures *cl_figure)
{
	double	k;
	double	eta;
	double	etai;
	double	etat;
	double	cosi;

	cosi = _dot(dir, normal);
	etai = 1;
	etat = cl_figure->material.refract;
	if (cl_figure->figures.sp.inside == 1)
	{
		k = etai;
		etai = etat;
		etat = k;
	}
	eta = etai / etat;
	k = 1 - eta * eta * (1 - cosi * cosi);
	if (k < 0)
		return (ray_reflect(_multy(dir, -1), normal));
	else
		return (_add(_multy(dir, eta), _multy(normal, (eta * cosi) - sqrt(k))));
}

int	trace_ray(t_p3 d, t_p3 O, t_scene *scene, int depth)
{
	double		closest_inter;
	t_figures	closest_figure;
	t_inter		inter;
	int			temp_color;
	int			reflect_color;

	closest_figure.flag = 0;
	closest_inter = try_intersections(d, O, scene->figures, &closest_figure);
	if (closest_inter == INFINITY)
		return (scene->background);
	inter.p = _add(O, _multy(d, closest_inter));
	inter.n = _norm(calculate_base_reflection \
						(inter.p, d, &closest_figure));
	temp_color = calculate_light(inter, \
					scene, _multy(d, -1), closest_figure);
	if (closest_figure.material.refract > 0)
		temp_color = trace_ray(ray_refraction(d, inter.n, \
						&closest_figure), inter.p, scene, depth);
	if (depth > 0 && closest_figure.material.reflective > 0)
		reflect_color = trace_ray(ray_reflect(_multy(d, -1), \
				inter.n), inter.p, scene, depth - 1);
	return (_cadd(_cproduct(temp_color, (1 - \
	closest_figure.material.reflective)), _cproduct(reflect_color, \
	closest_figure.material.reflective)));
}
