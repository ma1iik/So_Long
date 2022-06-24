/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misrailo <misrailo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 03:45:26 by misrailo          #+#    #+#             */
/*   Updated: 2022/05/15 04:05:10 by misrailo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	move_right(t_prog *map)
{
	map->player_y++;
	if (check_move(map->player_x, map->player_y, map) == 1)
	{
		map->mapdata[map->player_x][map->player_y] = 'P';
		map->mapdata[map->player_x][map->player_y - 1] = '0';
		map->move_nbr++;
		move_and_collect(map);
	}
	move_right1(map);
	if (check_move(map->player_x, map->player_y, map) == 3)
	{
		map->collect_nbr--;
		map->mapdata[map->player_x][map->player_y] = 'P';
		map->mapdata[map->player_x][map->player_y - 1] = '0';
		map->move_nbr++;
		move_and_collect(map);
	}
	map->is_player = mlx_xpm_file_to_image(map->mlx_ptr, map->player_right,
			&map->he, &map->wi);
	add_img(map, 0, 0);
}

void	move_right1(t_prog *map)
{
	if (check_move(map->player_x, map->player_y, map) == 0)
		map->player_y--;
	if (check_move(map->player_x, map->player_y, map) == 2 && map->collect_nbr)
		map->player_y--;
	if (check_move(map->player_x, map->player_y, map) == 2 && !map->collect_nbr)
	{
		free_tab(map);
		exit(EXIT_SUCCESS);
	}
}
