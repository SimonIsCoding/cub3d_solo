/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon <simon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 18:22:16 by simarcha          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/10/14 19:11:08 by simarcha         ###   ########.fr       */
=======
/*   Updated: 2024/10/09 10:15:22 by simon            ###   ########.fr       */
>>>>>>> 4a62c2705dc1b070a0addd7994aa5507d6fe5411
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

//I've coded the following functions thanks to this reference: 
//https://permadi.com/1996/05/ray-casting-tutorial-7/

//this function receives the player's coordinate. It returns the first vertical
//intersection between the player's ray and the following block
t_block	vertical_coordinate_first_block_point(t_player *player)
{
	t_block	a;

	a.reachable = 1;
	check_vertical_angle_value(player);
	if (ray_facing_right(player->angle) == 1)
		a.x = rounded_down(player->pos_x / BLOCK_SIZE) * BLOCK_SIZE + BLOCK_SIZE;
	else
<<<<<<< HEAD
		a.x = rounded_down(player->pos_x / BLOCK_SIZE) * BLOCK_SIZE - 1;
	//a.y = player->pos_y + (player->pos_x - a.x) * tan(player->angle * (PI / 180));
	a.y = player->pos_y - (a.x - player->pos_x) * tan(player->angle * (PI / 180));
=======
		a.x = rounded_down(ray->pos_x / BLOCK_SIZE) * BLOCK_SIZE - 1;

	//ce calcul de coordonne est eventuellement a reverifier
	a.y = ray->pos_y + (ray->pos_x - a.x) * tan(ray->angle * (PI / 180));
	printf("ray->pos_x = %f\nray->pos_y = %f\nray->angle = %f\n\n", 
			ray->pos_x, ray->pos_y, ray->angle);

	
	printf("a.x = %f\na.y = %f\n", a.x, a.y);

>>>>>>> 4a62c2705dc1b070a0addd7994aa5507d6fe5411
	return (a);
}

double	find_vertical_x_a(t_player *player)
{
	if (ray_facing_right(player->angle) == 1)
		return ((double)BLOCK_SIZE);
	return ((double)-BLOCK_SIZE);
}

//formula from the Pythagoras theorem to find the distance of the hypotenuse
//how to find the hypotenuse ? 
//We know the angle (player->ange) and the distance of one side of the triangle
//which is one cube (<=> BLOCK_SIZE unit)
double	find_vertical_y_a(t_player *player)
{
<<<<<<< HEAD
	return ((double)BLOCK_SIZE * tan(player->angle * (PI / 180)));
=======
	return ((double)BLOCK_SIZE * tan(ray->angle * (PI / 180)));
>>>>>>> 4a62c2705dc1b070a0addd7994aa5507d6fe5411
}

t_block	vertical_coordinate_next_block_point(t_player *player, t_block previous)
{
	t_block	next;
	double	x_a;
	double	y_a;

	x_a = find_vertical_x_a(player);
	y_a = find_vertical_y_a(player);
	next.x = previous.x + x_a;
	next.y = previous.y - y_a;
	next.reachable = true;
	return (next);
}

//REINITIALISE L'ANGLE UNE FOIS QUE TU AS TERMINE DE L'UTILISER
t_block	vertical_point_crossing_wall(t_vars *vars)
{
	t_block	current_in_block;
	t_block	current_in_px;
	t_block	next_in_block;
	t_block	next_in_px;
<<<<<<< HEAD

	if (vars->game->player->angle >= 90 && vars->game->player->angle < 270)
		vars->game->player->angle = 360 - vars->game->player->angle;
	current_in_px = vertical_coordinate_first_block_point(vars->game->player);
	current_in_block = convert_pixel_to_block(current_in_px);
	current_in_block.x = rounded_nearest_nb(current_in_block.x);
	current_in_block.y = rounded_nearest_nb(current_in_block.y);
	if (check_coordinates_in_map(vars, current_in_px) == 0)
	{
		current_in_px.reachable = false;
		vars->game->player->angle = vars->game->player->middle_angle;
		return (current_in_px);
	}
	while (check_coordinates_in_map(vars, current_in_px))
	{
		next_in_px = vertical_coordinate_next_block_point(vars->game->player, current_in_px);
		next_in_block = convert_pixel_to_block(next_in_px);
		next_in_block.x = rounded_nearest_nb(next_in_block.x);
		next_in_block.y = rounded_nearest_nb(next_in_block.y);
		if (check_coordinates_in_map(vars, next_in_px) == 0)
		{
			next_in_px.reachable = false;
			vars->game->player->angle = vars->game->player->middle_angle;
			return (current_in_px);
		}
		current_in_px = next_in_px;
		current_in_block = next_in_block;
	}
	vars->game->player->angle = vars->game->player->middle_angle;
	return (current_in_px);
}

	//printf("vertical final point in \033[1;34mblock\033[0m y = %0.f && x = %0.f\n", current_in_block.y, current_in_block.x);
	//printf("3 vertical final point in \033[1;31mpixels\033[0m y = %f && x = %f\n", current_in_px.y, current_in_px.x);
=======
	int		i = 0;

	current_in_px = vertical_coordinate_first_block_point(ray);//in pixel
	current_in_block = convert_pixel_to_block(current_in_px);//in block/cub unit
	printf("current point y = %f && x = %f\n", current_in_px.y, current_in_px.x);
	printf("current point y = %f && x = %f\n", current_in_block.y, current_in_block.x);
	current_in_block.x = rounded_nearest_nb(current_in_block.x);
	current_in_block.y = rounded_nearest_nb(current_in_block.y);
	while (map[(int)current_in_block.y][(int)current_in_block.x] == '0'
			|| map[(int)current_in_block.y][(int)current_in_block.x] == 'N')
	{
		printf("i = %i\ncurrent point y = %f && x = %f: _%c_\n", i++, current_in_block.y, current_in_block.x, map[(int)current_in_block.y][(int)current_in_block.x]);
		next_in_px = vertical_coordinate_next_block_point(ray, current_in_px);
		next_in_block = convert_pixel_to_block(next_in_px);
		next_in_block.x = rounded_nearest_nb(next_in_block.x);
		next_in_block.y = rounded_nearest_nb(next_in_block.y);
		current_in_px = next_in_px;
		current_in_block = next_in_block;
	}
	printf("final point y = %f && x = %f: _%c_\n", current_in_block.y, current_in_block.x, map[(int)current_in_block.y][(int)current_in_block.x]);
	return (next_in_px);
}

/*void	init_ray_for_test(t_ray *ray)
{
	ray->pos_x = 1 * 64;// = 160 the units have to be in pixels
	ray->pos_y = (8 * 64) + 10 * 64;// = 672
	ray->angle = PI / 4;
}*/

>>>>>>> 4a62c2705dc1b070a0addd7994aa5507d6fe5411
