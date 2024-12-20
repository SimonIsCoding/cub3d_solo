/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:29:36 by pde-masc          #+#    #+#             */
/*   Updated: 2024/11/12 17:18:57 by simarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	is_space(int c)
{
	return (c == '\t' || c == '\n' || c == ' '
		|| c == '\f' || c == '\r' || c == '\v');
}

int	can_open(char *file)
{
	int	fd;
	int	flag;

	fd = open(file, O_RDONLY);
	if (read(fd, 0, 0) < 0)
		flag = 0;
	else
		flag = 1;
	close(fd);
	return (flag);
}

//if the argv[1] is not '.cub', we return 0.
int	is_format(char *str, char *ext)
{
	int	len;
	int	formatlen;
	int	i;

	if (!str || !ext)
		return (0);
	len = ft_strlen(str);
	formatlen = ft_strlen(ext);
	if (len == 0 || formatlen == 0 || formatlen > len)
		return (0);
	i = 1;
	while (i <= formatlen && str[len - i] && ext[formatlen - i])
	{
		if (str[len - i] != ext[formatlen - i])
			return (0);
		i++;
	}
	return (1);
}

/*
check_id: it checks if a non-empty line has a valid identifier.
These identifiers can be (for now) "NO ", "SO ", "WE ", "EA ", "F ", or "C ".
It checks the length of the line first to avoid segfaults.
If identifier is a texture, it checks if its associated path can be opened.
*/
void	check_id(t_game *game, char *str)
{
	int	i;

	while (*str && is_space(*str))
		++str;
	if (!str || ft_strlen(str) < 2)
		handle_error(game, "Error\nMap has missing or unknown element\n");
	if (!ft_strncmp(str, "F ", 2) || !ft_strncmp(str, "C ", 2))
		return ;
	if (ft_strlen(str) < 3)
		handle_error(game, "Error\nMap has missing or unknown element\n");
	i = 3;
	while (str[i] && is_space(str[i]))
		++i;
	if (!ft_strncmp(str, "NO ", 3) || !ft_strncmp(str, "SO ", 3)
		|| !ft_strncmp(str, "WE ", 3) || !ft_strncmp(str, "EA ", 3))
	{
		if (can_open(str + i))
			return ;
		handle_error(game, "Error\nMap has incorrect texture path(s)\n");
	}
	handle_error(game, "Error\nMap has missing or unknown element\n");
}

/*
check_args: it does an input check for:
- number of arguments
- if the given map can be opened
- if the given map has correct extension (.cub)
*/
void	check_args(int argc, char **argv)
{
	if (argc != 2)
		handle_error(NULL, "Error\nToo few or too many arguments!\n");
	if (!is_format(argv[1], MAP_EXTENSION))
		handle_error(NULL, "Error\nMap has wrong extension!\n");
	if (!can_open(argv[1]))
		handle_error(NULL, "Error\nRead error!\n");
}
