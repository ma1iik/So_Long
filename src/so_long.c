/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misrailo <misrailo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 18:51:11 by misrailo          #+#    #+#             */
/*   Updated: 2022/05/16 19:49:29 by misrailo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	map_init(t_prog *map)
{
	map->mlx_ptr = mlx_init();
	map->player_right = "img/walk_right.xpm";
	map->player_left = "img/walk_left.xpm";
	map->player_down = "img/walk_down.xpm";
	map->player_up = "img/walk_up.xpm";
	map->collect = "img/collect.xpm";
	map->ground = "img/ground.xpm";
	map->exit = "img/door.xpm";
	map->wall = "img/wall.xpm";
	map->move_nbr = 0;
}

static void	img_init(t_prog *map)
{
	map->win_ptr = mlx_new_window(map->mlx_ptr, map->linemax * 32,
			map->linecount * 32, "So Long Game");
	map->is_collect = mlx_xpm_file_to_image(map->mlx_ptr, map->collect,
			&map->he, &map->wi);
	map->is_player = mlx_xpm_file_to_image(map->mlx_ptr, map->player_down,
			&map->he, &map->wi);
	map->is_ground = mlx_xpm_file_to_image(map->mlx_ptr, map->ground,
			&map->he, &map->wi);
	map->is_wall = mlx_xpm_file_to_image(map->mlx_ptr, map->wall,
			&map->he, &map->wi);
	map->is_exit = mlx_xpm_file_to_image(map->mlx_ptr, map->exit,
			&map->he, &map->wi);
}

void	add_img(t_prog *map, int i, int j)
{
	i = 0;
	while (map->mapdata[i])
	{
		j = 0;
		while (map->mapdata[i][j])
		{
			if (map->mapdata[i][j] == '1')
				mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
					map->is_wall, j * 32, i * 32);
			if (map->mapdata[i][j] == '0')
				mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
					map->is_ground, j * 32, i * 32);
			add_img2(map, i, j);
			j++;
		}
		i++;
	}
}

void	add_img2(t_prog *map, int i, int j)
{
	if (map->mapdata[i][j] == 'P')
	{
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->is_ground, j * 32, i * 32);
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->is_player, j * 32, i * 32);
	}
	if (map->mapdata[i][j] == 'C')
	{
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->is_ground, j * 32, i * 32);
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->is_collect, j * 32, i * 32);
	}
	if (map->mapdata[i][j] == 'E')
	{
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->is_ground, j * 32, i * 32);
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->is_exit, j * 32, i * 32);
	}
}

int	main(int argc, char **argv)
{
	t_prog		map;

	map.mapdata = NULL;
	map.collect_nbr = 0;
	if (argc == 2)
	{
		if (!check_ext(argv[1]))
			errors(1);
		add_tab(&map, argv[1]);
		add_map(&map, argv[1]);
		check_form(&map);
		wrong_char(&map);
		check_items(&map, 0, 0, 0);
		check_walls(&map);
		map_init(&map);
		img_init(&map);
		add_img(&map, 0, 0);
		mlx_hook(map.win_ptr, 2, 0, assign_key, &map);
		mlx_hook(map.win_ptr, 17, 0, ft_exit, &map);
		mlx_loop(map.mlx_ptr);
	}
	else
		errors(0);
}
