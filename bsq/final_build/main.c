/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:19:58 by akolupae          #+#    #+#             */
/*   Updated: 2025/02/04 18:46:34 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

int	main(int argc, char **argv)
{
	int		file_id;
	char	*map_str;
	int		**map_arr;
	int		i;
	char	file_name[255];

	i = 1;
	if (argc == 1)
	{
		ft_read_from_stdin(&file_name[0]);
		loop_args(&file_id, file_name, &map_str, &map_arr);
		free(map_str);
	}
	else
	{
		while (i < argc)
		{
			loop_args(&file_id, argv[i], &map_str, &map_arr);
			free(map_str);
			i++;
		}
	}
	return (0);
}

void	loop_args(int *file_id, char *arg_name, char **map_str, int ***map_arr)
{
	if (!open_file(file_id, arg_name))
		return;
	if (!read_file(file_id, map_str))
		return;
	if (map_is_valid(map_str))
	{
		if (!make_arr(map_str, map_arr))
			return;
		if (!close_file(file_id))
			return;
	}
	else
		write_map_error();
}

bool	open_file(int *file_id, char *file_name)
{
	*file_id = open(file_name, O_RDONLY);
	if (*file_id < 0)
	{
		write_error();
		exit(1);
		return (false);
	}
	return (true);
}

bool	read_file(int *file_id, char **map_str)
{
	int	bytes_read;

	*map_str = (char *)malloc(4000 * sizeof(char));
	if (!(*map_str))
	{
		write_error();
		return (false);
	}
	bytes_read = read(*file_id, *map_str, 4000);
	if (bytes_read < 0)
		return (false);
	(*map_str)[bytes_read] = '\0';
	return (true);
}

bool	close_file(int *file_id)
{
	if (close(*file_id) < 0)
	{
		write_error();
		exit(1);
		return (false);
	}
	return (true);
}
