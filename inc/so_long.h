/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ma1iik <ma1iik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 19:06:57 by misrailo          #+#    #+#             */
/*   Updated: 2024/10/31 03:06:53 by ma1iik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifdef __APPLE__  // macOS keycodes
#  define ESC 53
#  define W_KEY 13
#  define A_KEY 0
#  define S_KEY 1
#  define D_KEY 2
# else  // Linux keycodes
#  define ESC 65307
#  define W_KEY 119
#  define A_KEY 97
#  define S_KEY 115
#  define D_KEY 100
# endif

# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include <string.h>

typedef struct s_prog
{
	char		**mapdata;
	int			linemax;
	int			linecount;
	void		*mlx_ptr;
	void		*win_ptr;

	char		*player_right;
	char		*player_left;
	char		*player_down;
	char		*player_up;
	char		*collect;
	char		*ground;
	char		*exit;
	char		*wall;

	int			he;
	int			wi;
	void		*is_collect;
	void		*is_ground;
	void		*is_player;
	void		*is_exit;
	void		*is_wall;

	int			player_x;
	int			player_y;
	int			collect_nbr;

	int			move_nbr;
}				t_prog;

int		main(int argc, char **argv);
void	check_items(t_prog *map, int p, int e, int c);
void	add_img2(t_prog *map, int i, int j);
int		check_move(int x, int y, t_prog *map);
void	free_tab(t_prog *map);
void	move_up(t_prog *map);
void	move_down(t_prog *map);
void	move_right(t_prog *map);
void	move_left(t_prog *map);
void	move_and_collect(t_prog *map);
void	ground_aff(t_prog *map, int i, int j);
void	move_up1(t_prog *map);
void	move_down1(t_prog *map);
void	move_right1(t_prog *map);
void	move_left1(t_prog *map);
void	add_img(t_prog *map, int i, int j);
int		ft_exit(void);
int		assign_key(int key, t_prog *map);
void	errors(int x);
void	add_tab(t_prog *map, char *argv);
int		check_ext(char *argv);
void	add_map(t_prog *map, char *argv);
void	check_form(t_prog *map);
void	wrong_char(t_prog *map);
void	check_walls(t_prog *map);

#endif
