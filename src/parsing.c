/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misrailo <misrailo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 04:08:35 by misrailo          #+#    #+#             */
/*   Updated: 2022/05/16 17:49:10 by misrailo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	add_map(t_prog *map, char *argv)
{
	int	fd;
	int	i;
	int	height;

	height = map->linecount;
	i = 0;
	map->mapdata = malloc(sizeof(char *) * map->linecount + 1);
	fd = open(argv, O_RDONLY);
	while (height > 0)
	{
		map->mapdata[i] = get_next_line(fd);
		i++;
		map->mapdata[i] = 0;
		height--;
	}
	map->mapdata[i] = 0;
	close (fd);
}

void	check_form(t_prog *map)
{
	int		i;
	int		tmp;

	i = 1;
	tmp = ft_strlen(map->mapdata[0]);
	while (map->mapdata[i])
	{
		if (tmp != ft_strlen(map->mapdata[i]))
			errors(5);
		i++;
	}
}

void	wrong_char(t_prog *map)
{
	int		i;
	int		j;

	i = 0;
	while (map->mapdata[i])
	{
		j = 0;
		while (map->mapdata[i][j])
		{
			if (map->mapdata[i][j] != 'P' && map->mapdata[i][j] != 'E'
				&& map->mapdata[i][j] != '1' && map->mapdata[i][j] != '0'
				&& map->mapdata[i][j] != 'C')
				errors(6);
			j++;
		}
		i++;
	}
}

void	check_items(t_prog *map, int p, int e, int c)
{
	int		i;
	int		j;

	i = 0;
	while (map->mapdata[i])
	{
		j = 0;
		while (map->mapdata[i][j])
		{
			if (map->mapdata[i][j] == 'P')
			{
				map->player_x = i;
				map->player_y = j;
				p++;
			}
			else if (map->mapdata[i][j] == 'E')
				e++;
			else if (map->mapdata[i][j] == 'C')
				map->collect_nbr++;
			j++;
		}
		i++;
	}
	if (p != 1 || e != 1 || map->collect_nbr <= 0)
		errors(7);
}

void	check_walls(t_prog *map)
{
	int		i;
	int		c;

	c = 0;
	i = 0;
	map->linemax = (ft_strlen(&map->mapdata[i][0]));
	while (map->mapdata[0][c] != '\0')
	{
		if (map->mapdata[0][c++] != '1')
			errors(8);
	}
	while (i < map->linecount)
	{
		if (map->mapdata[i][0] != '1'
			|| map->mapdata[i][map->linemax - 1] != '1')
			errors(8);
		i++;
	}
	c = 0;
	while (map->mapdata[0][c] != '\0')
	{
		if (map->mapdata[map->linecount - 1][c++] != '1')
			errors(8);
	}
}
