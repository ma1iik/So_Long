/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misrailo <misrailo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 04:06:16 by misrailo          #+#    #+#             */
/*   Updated: 2022/05/15 04:09:48 by misrailo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_exit(void)
{
	exit(0);
}

void	free_tab(t_prog *map)
{
	int	i;

	i = 0;
	while (map->mapdata[i])
	{
		free(map->mapdata[i]);
		map->mapdata[i] = NULL;
		i++;
	}
	free(map->mapdata);
}

void	errors(int x)
{
	if (x == 0)
		write(2, "Error!\nWrong ARG number.\n", 25);
	if (x == 1)
		write(2, "Error!\nWrong extention.\n", 24);
	if (x == 2)
		write(2, "Error!\nArgument is a directory\n", 31);
	if (x == 3)
		write(2, "Error!\nFile not properly read.\n", 31);
	if (x == 4)
		write(2, "Error!\nCouldn't read Map file.\n", 31);
	if (x == 5)
		write(2, "Error!\nMap not rectangle.\n", 26);
	if (x == 6)
		write(2, "Error!\nMap contains wrong characters.\n", 38);
	if (x == 7)
		write(2, "Error!\nMap contains wrong number of elements.\n", 46);
	if (x == 8)
		write(2, "Error!\nWalls error on the map.\n", 31);
	exit(EXIT_FAILURE);
}

void	add_tab(t_prog *map, char *argv)
{
	int		fd;
	int		i;

	i = 0;
	map->linecount = 0;
	fd = open(argv, O_DIRECTORY);
	if (fd != -1)
		errors(2);
	else
	{
		fd = open(argv, O_RDONLY);
		if (fd == -1)
			errors(3);
	}
	while (get_next_line(fd))
		map->linecount++;
}

int	check_ext(char *argv)
{
	int	i;

	i = 0;
	while (argv[i] != '\0')
	{
		if (argv[i] == '.' && argv[i + 1] == 'b' && argv[i + 2] == 'e'
			&& argv[i + 3] == 'r' && argv[i + 4] == '\0')
			return (1);
		i++;
	}
	return (0);
}
