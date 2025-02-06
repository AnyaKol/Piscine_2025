/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_largest_square.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwong <cwong@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:47:19 by cwong             #+#    #+#             */
/*   Updated: 2025/02/04 13:47:32 by cwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

void	ft_find_largest_square(int **map, int row, int col, char *characters)
{
	int		i;
	int		j;
	int		largest;
	char	**result;

	largest = 0;
	ft_allocate_result(&result, row, col);
	ft_fill_map(map, row, col, &largest);
	ft_find_largest(map, row, col, largest);
	i = 0;
	while (i++ < row)
	{
		j = 0;
		while (j++ < col)
		{
			if (map[i - 1][j - 1] == -1)
				result[i - 1][j - 1] = characters[2];
			else if (map[i - 1][j - 1] == 0)
				result[i - 1][j - 1] = characters[1];
			else
				result[i - 1][j - 1] = characters[0];
		}
	}
	ft_print_result(result, row, col);
	ft_free_memory_char(result, row);
}

void	ft_allocate_result(char ***result, int row, int col)
{
	int	i;

	*result = NULL;
	*result = (char **)malloc(row * sizeof(char *));
	if (!(*result))
		ft_free_memory_char(*result, row);
	i = 0;
	while (i < row)
	{
		(*result)[i] = (char *)malloc(col * sizeof(char));
		if (!((*result)[i]))
			ft_free_memory_char(*result, row);
		i++;
	}
}

void	ft_fill_map(int **map, int row, int col, int *largest)
{
	int	i;
	int	j;

	i = 0;
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			if (map[i][j] == -1)
				map[i][j] = 0;
			else if (i == 0 || j == 0)
				map[i][j] = 1;
			else
				map[i][j] = ft_min(map[i - 1][j], map[i][j - 1],
						map[i - 1][j - 1]) + 1;
			if (map[i][j] > *largest)
				*largest = map[i][j];
			j++;
		}
		i++;
	}
}

void	ft_find_largest(int **map, int row, int col, int largest)
{
	int	i;
	int	j;

	i = 0;
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			if (map[i][j] == largest)
			{
				ft_mark_square(map, i, j, largest);
				break ;
			}
			j++;
		}
		i++;
	}
}

void	ft_print_result(char **result, int row, int col)
{
	int	i;

	i = 0;
	while (i < row)
	{
		write(1, result[i], col);
		write(1, "\n", 1);
		i++;
	}
	write(1, "\n", 1);
}
