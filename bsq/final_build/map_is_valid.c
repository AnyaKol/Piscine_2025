/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:48:35 by akolupae          #+#    #+#             */
/*   Updated: 2025/02/04 19:07:09 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

bool	map_is_valid(char **map_str)
{
	int	i;
	int	len;
	int	size;

	i = 0;
	while ((*map_str)[i] != '\n')
		i++;
	if (i < 5)
		return (false);
	len = line_len(*map_str);
	size = lines_num(*map_str);
	if (len == 0 || size == 0 || !check_free_box(*map_str, i))
		return (false);
	if (!check_len(*map_str, len, i) || !compare_size(*map_str, size))
		return (false);
	return (true);
}

bool	check_len(char *str, int len, int i)
{
	int	new_len;

	while (str[i] != '\0')
	{
		if (str[i] != '\n')
		{
			new_len = 0;
			while (str[i] != '\r')
			{
				new_len++;
				i++;
			}
			if (new_len != len)
				return (false);
		}
		i++;
	}
	return (true);
}

bool	compare_size(char *str, int size)
{
	int	i;
	int	calc_size;

	i = 0;
	calc_size = -1;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			calc_size++;
		i++;
	}
	if (calc_size != size)
		return (false);
	return (true);
}

bool	check_free_box(char *str, int i)
{
	char	marks[4];
	int		start;

	start = i;
	if (!find_marks(str, &marks[0]))
		return (false);
	while (str[start] != '\0')
	{
		if (str[start] == marks[0])
			return (true);
		start++;
	}
	return (false);
}
