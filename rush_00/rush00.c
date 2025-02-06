/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:38:23 by akolupae          #+#    #+#             */
/*   Updated: 2025/01/18 16:16:23 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush(int max_col, int max_row)
{
	int col;
	int row;

	row = 1;
	while (row <= max_row)
	{
		col = 1;
		while (col <= max_col)
		{
			if (row == 1 || row == max_row)
			{
				if (col == 1 || col == max_col)
				{
					write(1, "o", 1);
				}
				else
				{
					write(1, "-", 1);
				}
			}
			else
			{
				if (col == 1 || col == max_col)
				{
					write(1, "|", 1);
				}
				else
				{
					write(1, " ", 1);
				}
			}
			col = col + 1;
		}
		write(1, "\n", 1);
		row = row +1;
	}
}
