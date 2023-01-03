/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:52:24 by gpinchuk          #+#    #+#             */
/*   Updated: 2023/01/02 14:23:20 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_material fill_material(char **str, t_scene *scene)
{
	t_material	material;
	int			number;

	number =  (int)stof(str, scene, 3);
	if (number == 1)
		material.gloss = -1;
	else if  (number == 2)
		material.gloss = 1000;
	else if  (number == 3)
		material.gloss = 3000;
	else
		material.gloss = -1;
	// if else (number == 4)
	// if else (number == 5)
	// else
	// {
	// 	fatal_error_v2(scene);
	// }
	return (material);
}