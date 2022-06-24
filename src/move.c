/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misrailo <misrailo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 04:10:20 by misrailo          #+#    #+#             */
/*   Updated: 2022/05/16 18:48:36 by misrailo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	assign_key(int key, t_prog *map)
{
	if (key == ESC)
		exit(0);
	if (key == S_KEY)
		move_down(map);
	if (key == W_KEY)
		move_up(map);
	if (key == D_KEY)
		move_right(map);
	if (key == A_KEY)
		move_left(map);
	return (0);
}

void	move_and_collect(t_prog *map)
{
	write(STDOUT_FILENO, "move :", 6);
	ft_putnbr_fd(map->move_nbr, STDOUT_FILENO);
	write(STDOUT_FILENO, "\n", 1);
	write(STDOUT_FILENO, "collectible :", 13);
	ft_putnbr_fd(map->collect_nbr, STDOUT_FILENO);
	write(STDOUT_FILENO, "\n", 1);
}

int	check_move(int x, int y, t_prog *map)
{
	if (map->mapdata[x][y] == '1')
		return (0);
	if (map->mapdata[x][y] == '0')
		return (1);
	if (map->mapdata[x][y] == 'E')
		return (2);
	if (map->mapdata[x][y] == 'C')
		return (3);
	return (4);
}
