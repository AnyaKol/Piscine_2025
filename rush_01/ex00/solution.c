/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 10:42:15 by akolupae          #+#    #+#             */
/*   Updated: 2025/01/26 15:51:18 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_views(char *row, int left, int right);
int	test_solution(char grid[4][4], char *views);
int	test_row(char grid[4][4], char *views);
int	test_col(char grid[4][4], char *views);
int	solution(char grid[4][4], int count, int avail[8][4], char *views);

int	solution(char grid[4][4], int count, int avail[8][4], char *views)
{
	int	i;
	int	result;

	i = 0;
	while (i < 4)
	{
		if (avail[count % 4][i] == 1 && avail[count / 4 + 4][i] == 1)
		{
			grid[count / 4][count % 4] = i + 1 + '0';
			if (count / 4 < 3 || count % 4 < 3)
			{
				avail[count % 4][i] = 0;
				avail[count / 4 + 4][i] = 0;
				result = solution(grid, count + 1, avail, views);
				avail[count % 4][i] = 1;
				avail[count / 4 + 4][i] = 1;
				if (result)
					return (1);
			}
			else
				return (test_solution(grid, views));
		}
		i++;
	}
	return (0);
}

int	test_solution(char grid[4][4], char *views)
{
	if (test_row(grid, views) && test_col(grid, views))
		return (1);
	return (0);
}

int	test_row(char grid[4][4], char *views)
{
	int		i;
	int		row;
	int		result;
	char	str[4];

	row = 0;
	while (row < 4)
	{
		i = 0;
		while (i < 4)
		{
			str[i] = grid[row][i];
			i++;
		}
		result = check_views(str, views[8 + row] - 48, views[12 + row] - 48);
		if (result == 0)
			return (0);
		row++;
	}
	return (1);
}

int	test_col(char grid[4][4], char *views)
{
	int		i;
	int		col;
	int		result;
	char	str[4];

	col = 0;
	while (col < 4)
	{
		i = 0;
		while (i < 4)
		{
			str[i] = grid[i][col];
			i++;
		}
		result = check_views(str, views[col] - 48, views[4 + col] - 48);
		if (result == 0)
		{
			return (0);
		}
		col++;
	}
	return (1);
}
