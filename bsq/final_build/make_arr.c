/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:48:35 by akolupae          #+#    #+#             */
/*   Updated: 2025/02/04 18:50:03 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

bool	make_arr(char **map_str, int ***map_arr)
{
	int		size;
	int		len;
	int		i;
	char	marks[4];

	size = lines_num(*map_str);
	len = line_len(*map_str);
	*map_arr = (int **)malloc(size * sizeof(int *));
	if (!(*map_arr))
	{
		write_error();
		return (false);
	}
	i = 0;
	while (i < size)
	{
		(*map_arr)[i] = make_row(map_str, i, len);
		i++;
	}
	find_marks(*map_str, &marks[0]);
	ft_find_largest_square(*map_arr, size, len, marks);
	ft_free_memory_int(*map_arr, size);
	return (true);
}

int	*make_row(char **map_str, int row, int len)
{
	int	str_i;
	int	i;
	int	*row_ptr;

	row_ptr = (int *)malloc(len * sizeof(int));
	if (!row_ptr)
	{
		write_error();
		return (false);
	}
	str_i = 0;
	while ((*map_str)[str_i] != '\n')
		str_i++;
	str_i = str_i + row * (len + 2) + 1;
	i = 0;
	while (i < len)
	{
		if ((*map_str)[str_i + i] == 'o')
			row_ptr[i] = -1;
		else
			row_ptr[i] = 0;
		i++;
	}
	return (row_ptr);
}

int	lines_num(char *str)
{
	int		i;
	int		end;
	int		lines;

	end = 0;
	while (str[end] != '\r')
		end++;
	end = end - 3;
	i = 0;
	lines = 0;
	while (i < end)
	{
		lines = lines * 10 + (str[i] - '0');
		i++;
	}
	return (lines);
}

int	line_len(char *str)
{
	int		i;
	int		len;

	i = 0;
	while (str[i] != '\n')
		i++;
	len = 0;
	i++;
	while (str[i] != '\r')
	{
		len++;
		i++;
	}
	return (len);
}
