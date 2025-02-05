/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 21:59:03 by gpinchuk          #+#    #+#             */
/*   Updated: 2023/01/24 16:36:17 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	parse(char *str, t_scene *scene)
{	
	if (*str == 'p' && *(str + 1) == 'l' && str++)
		parse_plane(&str, scene);
	else if (*str == 'l' && str++)
		parse_light(&str, scene);
	else if (*str == 'A' && str++)
		parse_ambient(&str, scene);
	else if (*str == 'c' && *(str + 1) == 'y' && str++)
		parse_cylinder(&str, scene);
	else if (*str == 'c' && str++)
		parse_camera(&str, scene);
	else if (*str == 's' && *(str + 1) == 'p' && str++)
		parse_sphere(&str, scene);
	else if (*str == 't' && *(str + 1) == 'r' && str++)
		parse_triangle(&str, scene);
	else if (*str == 'h' && *(str + 1) == 'y' && str++)
		parse_hyperboloid(&str, scene);
	else if (*str != '#')
	{
		print_error("no such identifier:");
		return (print_error(str));
	}
	return (1);
}

void	create_scene(t_scene **scene)
{
	(*scene) = (t_scene *)malloc(sizeof(t_scene));
	(*scene)->figures = NULL;
	(*scene)->lights = NULL;
	(*scene)->mlx = NULL;
	(*scene)->background = 0;
	(*scene)->height = 1080;
	(*scene)->width = 1920;
}

t_scene	*parse_scene(char *file_name)
{
	int		fd;
	char	*str;
	t_scene	*scene;

	fd = open(file_name, O_RDONLY);
	scene = NULL;
	if (fd == -1)
		fatal_error("no such file");
	create_scene(&scene);
	init_mlx(scene);
	str = get_next_line(fd);
	while (str)
	{
		ft_putstr_fd(str, 2);
		if (*str != '\n')
			if (parse(str, scene) == -1)
				parse_error(scene, fd);
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	close(fd);
	return (scene);
}
