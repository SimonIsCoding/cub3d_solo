/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_intersection.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon <simon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:25:17 by simarcha          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/10/16 18:37:01 by simarcha         ###   ########.fr       */
=======
/*   Updated: 2024/10/09 10:14:40 by simon            ###   ########.fr       */
>>>>>>> 4a62c2705dc1b070a0addd7994aa5507d6fe5411
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

//I've coded the following functions thanks to this reference: 
//https://permadi.com/1996/05/player-casting-tutorial-7/

//We want to convert the position of our character (=player) that we have in 
//pixel into cubs unit.
//Given that the cubs unit are bigger than pixels, this returns an approximation

//This function gives us the coordinates of the character into block/cubs unit.
//tan receives an angle in radian but we work in degrees, so we add * (PI / 180)
//to convert it in radians
<<<<<<< HEAD
static t_block	horizontal_coordinate_first_block_point(t_player *player)
=======
static t_block	horizontal_coordinate_first_block_point(t_ray *ray)
>>>>>>> 4a62c2705dc1b070a0addd7994aa5507d6fe5411
{
	t_block	a;

	a.reachable = 1;
	check_horizontal_angle_value(player);
	if (ray_facing_up(player->angle) == 1)
		a.y = rounded_down(player->pos_y / BLOCK_SIZE) * BLOCK_SIZE - 1;
	else
<<<<<<< HEAD
		a.y = rounded_down(player->pos_y / BLOCK_SIZE) * BLOCK_SIZE + BLOCK_SIZE;
	a.x = player->pos_x + (a.y - player->pos_y) / tan(player->angle * (PI / 180));
	// a.x = player->pos_x - (a.y - player->pos_y) / tan(player->angle * (PI / 180));
=======
		a.y = rounded_down(ray->pos_y / BLOCK_SIZE) * BLOCK_SIZE + BLOCK_SIZE;
	// printf("ray->pos_x = %f\nray->pos_y = %f\nray->angle = %f\n\n", 
	// 		ray->pos_x, ray->pos_y, ray->angle);
	a.x = ray->pos_x + (ray->pos_y - a.y) / tan(ray->angle * (PI / 180));

	//printf("a.x = %f\na.y = %f\n", a.x, a.y);
>>>>>>> 4a62c2705dc1b070a0addd7994aa5507d6fe5411
	return (a);
}

static double	find_horizontal_x_a(t_player *player)
{
<<<<<<< HEAD
	return (rounded_down((double)BLOCK_SIZE / tan(player->angle * PI / 180)));
=======
	return (rounded_down((double)BLOCK_SIZE / tan(ray->angle * (PI / 180))));
>>>>>>> 4a62c2705dc1b070a0addd7994aa5507d6fe5411
}

static double	find_horizontal_y_a(t_player *player)
{
	if (ray_facing_up(player->angle) == 1)
		return ((double)-BLOCK_SIZE);
	return ((double)BLOCK_SIZE);
}

t_block	horizontal_coordinate_next_block_point(t_player *player, t_block previous)
{
	t_block	next;
	double	x_a;
	double	y_a;

	x_a = find_horizontal_x_a(player);
	y_a = find_horizontal_y_a(player);
	next.x = previous.x + x_a;
	next.y = previous.y + y_a;
	next.reachable = true;
	return (next);
}

//Ensuite on a besoin d'une fonction/condition qui nous dit que s'il y a un mur
//au point en (convertit en block) alors, on stop le process
//Sinon on continue jusqu'a le stopper

//This function find the first point, it means where the player is on the vars->game->map
//then checks if there is a wall or not. If there is no, we will go on 
//until finding one to return the point where the wall is

//une fois que l'on a next_in_x, on peut calculer la distance en pixel parcourue
//REINITIALISE L'ANGLE UNE FOIS QUE TU AS TERMINE DE L'UTILISER
t_block	horizontal_point_crossing_wall(t_vars *vars)
{
	t_block	current_in_block;
	t_block	current_in_px;
	t_block	next_in_block;
	t_block	next_in_px;
<<<<<<< HEAD

	if (vars->game->player->angle > 180 && vars->game->player->angle < 360)
	 	vars->game->player->angle = 540 - vars->game->player->angle;
	current_in_px = horizontal_coordinate_first_block_point(vars->game->player);
	current_in_block = convert_pixel_to_block(current_in_px);
	current_in_block.x = rounded_nearest_nb(current_in_block.x);
	current_in_block.y = rounded_nearest_nb(current_in_block.y);
	if (check_coordinates_in_map(vars, current_in_px) == 0)
	{
		current_in_px.reachable = false;
//		printf("horizontal_point_crossing_wall return 1\n");
		vars->game->player->angle = vars->game->player->middle_angle;
		return (current_in_px);
	}
	// while (vars->game->map[(int)current_in_block.y][(int)current_in_block.x] == '0'
	// 		|| vars->game->map[(int)current_in_block.y][(int)current_in_block.x] == 'V')
	while (check_coordinates_in_map(vars, current_in_px))
	{
		next_in_px = horizontal_coordinate_next_block_point(vars->game->player, current_in_px);
		next_in_block = convert_pixel_to_block(next_in_px);
		next_in_block.x = rounded_nearest_nb(next_in_block.x);
		next_in_block.y = rounded_nearest_nb(next_in_block.y);
//		printf("horizontal final point in \033[1;31mpixels\033[0m y = %f && x = %f\n", current_in_px.y, current_in_px.x);
//		printf("horizontal final point in \033[1;34mblock\033[0m y = %0.f && x = %0.f\n", current_in_block.y, current_in_block.x);
	
		if (check_coordinates_in_map(vars, next_in_px) == 0)
		{
			next_in_px.reachable = false;
	// 		printf("horizontal_point_crossing_wall return 2\n");
	// printf("horizontal final point in \033[1;31mpixels\033[0m y = %f && x = %f\n", current_in_px.y, current_in_px.x);
	// printf("horizontal final point in \033[1;34mblock\033[0m y = %0.f && x = %0.f\n", current_in_block.y, current_in_block.x);

			vars->game->player->angle = vars->game->player->middle_angle;
			return (current_in_px);
		}
		current_in_px = next_in_px;
		current_in_block = next_in_block;
	}
	// printf("horizontal_point_crossing_wall return 3\n");
	// printf("horizontal final point in \033[1;31mpixels\033[0m y = %f && x = %f\n", current_in_px.y, current_in_px.x);
	// printf("horizontal final point in \033[1;34mblock\033[0m y = %0.f && x = %0.f\n", current_in_block.y, current_in_block.x);
	vars->game->player->angle = vars->game->player->middle_angle;
	return (current_in_px);
=======
	int	i = 0;

	current_in_px = horizontal_coordinate_first_block_point(ray);//in pixel
	current_in_block = convert_pixel_to_block(current_in_px);//in block/cub unit
	printf("current point y = %f && x = %f\n", current_in_px.y, current_in_px.x);
	printf("current point y = %f && x = %f\n", current_in_block.y, current_in_block.x);
	current_in_block.x = rounded_nearest_nb(current_in_block.x);
	current_in_block.y = rounded_nearest_nb(current_in_block.y);
	while (map[(int)current_in_block.y][(int)current_in_block.x] == '0'
			|| map[(int)current_in_block.y][(int)current_in_block.x] == 'N')
	{
		printf("i = %i\ncurrent point y = %f && x = %f: _%c_\n", i++, current_in_block.y, current_in_block.x, map[(int)current_in_block.y][(int)current_in_block.x]);
		next_in_px = horizontal_coordinate_next_block_point(ray, current_in_px);
		next_in_block = convert_pixel_to_block(next_in_px);
		next_in_block.x = rounded_nearest_nb(next_in_block.x);
		next_in_block.y = rounded_nearest_nb(next_in_block.y);
		current_in_px = next_in_px;
		current_in_block = next_in_block;
	}
	printf("final point y = %f && x = %f: _%c_\n", current_in_block.y, current_in_block.x, map[(int)current_in_block.y][(int)current_in_block.x]);
	return (next_in_px);
>>>>>>> 4a62c2705dc1b070a0addd7994aa5507d6fe5411
}
//une fois que l'on a next_in_x, on peut calculer la distance en pixel parcourue

/*void	test_fixing_errors(t_vars *vars)
{
<<<<<<< HEAD
//1
// 	t_block	horizontal_point_in_px;
// 	t_block	vertical_point_in_px;

// 	horizontal_point_in_px = horizontal_point_crossing_wall(vars);
// 	printf("horizontal point.x = %f\n", horizontal_point_in_px.x);
// 	printf("horizontal point.y = %f\n", horizontal_point_in_px.y);
// 	printf("horizontal point.reachable = %i\n", horizontal_point_in_px.reachable);
	// vertical_point_in_px = vertical_point_crossing_wall(vars);
	// printf("vertical point.x = %f\n", vertical_point_in_px.x);
	// printf("vertical point.y = %f\n", vertical_point_in_px.y);
	// printf("vertical point.reachable = %i\n", vertical_point_in_px.reachable);
//2
	// t_block	wall_point_px;
	// t_block	wall_point_in_block;
	double	distance_hypotenuse;
	distance_hypotenuse = calculate_best_distance(vars, vars->game->player->middle_angle);
	printf("fin\n");
	printf("distance_hypotenuse = %f\n", distance_hypotenuse);
	printf("distance_hypotenuse in  block = %f\n", distance_hypotenuse / 64);
	calculate_projected_wall_height(vars, distance_hypotenuse);
	// printf("wall_point_px.x = %f\n", wall_point_px.x);
	// printf("wall_point_px.y = %f\n", wall_point_px.y);
	// wall_point_in_block = convert_pixel_to_block(wall_point_px);
	// printf("wall_point_in_block.x = %f\n", rounded_down(wall_point_in_block.x));
	// printf("wall_point_in_block.y = %f\n", rounded_down(wall_point_in_block.y));
	
}*/

// printf("3 horizontal final point in \033[1;31mpixels\033[0m y = %f && x = %f\n", current_in_px.y, current_in_px.x);
// printf("horizontal final point in \033[1;34mblock\033[0m y = %0.f && x = %0.f\n", current_in_block.y, current_in_block.x);
=======
	ray->pos_x = 1 * 64;// = 160 the units have to be in pixels
	ray->pos_y = (8 * 64) + 10 * 64;// = 672
	ray->angle = 45;
}

>>>>>>> 4a62c2705dc1b070a0addd7994aa5507d6fe5411
