/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narrospi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:32:33 by narrospi          #+#    #+#             */
/*   Updated: 2024/12/05 13:33:02 by narrospi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG__BONUS_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <stdlib.h>
# include "../lib/libft/libft.h"
# include "../lib/printf/ft_printf.h"

# define PNG_WALL "./textures/walls_3.png"
# define WALL_SPRITE "./textures/so_long_tree2.png"
# define FRONT_PLAYER_SPRITE "./textures/so_long_front.png"
# define BACK_PLAYER_SPRITE "./textures/so_long_back.png"
# define LEFT_PLAYER_SPRITE "./textures/so_long_left.png"
# define RIGHT_PLAYER_SPRITE "./textures/so_long_right.png"
# define CHIP_SPRITE "./textures/so_long_ball.png"
# define FLOOR_SPRITE "./textures/so_long_floor.png"
# define EXITE_SPRITE "./textures/so_long_house.png"
# define EXITE_SPRITE_OPEN "./textures/so_long_dragon.png"
# define EXIT_PLAYER_SPRITE "./textures/so_long_house_goku.png"

# define ZERO_IMG "./textures/zero_img.png"
# define ONE_IMG "./textures/one_img.png"
# define TWO_IMG "./textures/two_img.png"
# define THREE_IMG "./textures/three_img.png"
# define FOUR_IMG "./textures/four_img.png"
# define FIVE_IMG "./textures/five_img.png"
# define SIX_IMG "./textures/six_img.png"
# define SEVEN_IMG "./textures/seven_img.png"
# define EIGHT_IMG "./textures/eight_img.png"
# define NINE_IMG "./textures/nine_img.png"

# define WALL 	'1'
# define FLOOR 	'0'
# define COLLECTIVES 'C'
# define EXIT 'E'
# define PLAYER 'P'

# define WIDTH	100
# define HEIGHT	100
# define SIZE 100

# define CHAR_COPY "CEP"
# define IS_FILLED "1X"

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

typedef struct s_images
{
	mlx_image_t	*floor_img;
	mlx_image_t	*wall_img;
	mlx_image_t	*front_img;
	mlx_image_t	*back_img;
	mlx_image_t	*right_img;
	mlx_image_t	*left_img;
	mlx_image_t	*collect_img;
	mlx_image_t	*exit_close_img;
	mlx_image_t	*open_img;
	mlx_image_t	*exit_player_img;
	mlx_image_t *numbers[10];
	}	t_images;

typedef struct s_map
{
	char	**full;
	char	**copy;
	int		cols;
	int		rows;
	int		collects;
	int		collects_total;
	int		exit;
	int		walls;
	int		floor;
	int		players;
	int		flag;
}	t_map;

typedef struct s_game
{
	mlx_t			*mlx;
	t_map			map;
	int				moves;
	t_position		player;
	t_position		exit;
	t_images		*images;
	mlx_image_t		*player_sprite;
	mlx_image_t		*exit_sprite;
}	t_game;

//so_long.c
void	victory_game(t_game *game);
void	close_win(void	*param);

//validation.c
void	check_parameters(int ac, char **av, t_game *game);
void	check_rows_cols(t_game *game);
void	check_map_size(t_game *game);
void	check_colectables(t_game *game);

//utils.c
void	load_images(t_game *game);
void	load_numbers(t_game *game);
void	free_game_map(char **mapi);
void	free_map_copy(char **map, int rows);

//init_map.c
void	init_map(t_game *game, char *file_map);
void	init_vars(t_game *game);
void	check_map(t_game *game);

//init_game.c
void	render_map(t_game *game);
void	player_moves(t_game *game, int new_x, int new_y, mlx_image_t *sprite);
void	init_game(t_game *game);

//texture.c
void	render_wall(t_game *game, int x, int y);
void	render_floor(t_game *game, int x, int y);
void	render_collects(t_game *game, int x, int y);
void	render_player(t_game *game, int x, int y);
void	render_exit(t_game *game, int x, int y);

//handle_moves.c
void	render_map_cell(t_game *game, int x, int y);
void	update_player_position(t_game *game, int new_x, int new_y);
void	handle_exit(t_game *game, int new_x, int new_y);
void	handle_collective(t_game *game, int new_x, int new_y);
void	handle_floor_or_collective(t_game *game, int new_x, int new_y);

//flood_fill.c
void	copy_map(t_game *game);
void	flood_fill(t_game *game, int x, int y, char character);
void	find_remain_object(t_game *game, int x, int y);
void	check_gameable(t_game *game);

//finish.c
void	free_wall(t_game *game);
void	free_images(t_game *game);
void	clean_up(t_game *game);
void	print_counter(t_game *game);

//error.c
void	error_free(char *str, t_game *game);
void	error_general(char *str);
void	error_list(char *str, t_game *game);
void	error_map(char *str, t_game *game);

#endif
