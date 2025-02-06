/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   largest_square_helper.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwong <cwong@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:30:00 by cwong             #+#    #+#             */
/*   Updated: 2025/02/04 14:30:01 by cwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

int	ft_min(int a, int b, int c)
{
	if (a < b && a < c)
		return (a);
	else if (b < c)
		return (b);
	else
		return (c);
}

void	ft_mark_square(int **map, int row, int col, int largest)
{
	int	a;
	int	b;

	a = row;
	while (a > row - largest)
	{
		b = col;
		while (b > col - largest)
		{
			map[a][b] = -1;
			b--;
		}
		a--;
	}
}

void	ft_free_memory_char(char **grid, int row)
{
	int	i;

	i = 0;
	while (i < row)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

void	ft_free_memory_int(int **grid, int row)
{
	int	i;

	i = 0;
	while (i < row)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}
