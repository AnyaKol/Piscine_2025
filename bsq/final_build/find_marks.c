/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_marks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:48:35 by akolupae          #+#    #+#             */
/*   Updated: 2025/02/04 18:55:36 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

bool	find_marks(char *str, char *marks)
{
	int		i;
	int		j;

	i = 0;
	while (str[i] != '\r')
		i++;
	i = i - 3;
	j = 0;
	while (str[i + j] != '\r')
	{
		marks[j] = str[i + j];
		j++;
	}
	marks[4] = '\0';
	if (!check_marks(marks))
	{
		write_error();
		return (false);
	}
	return (true);
}

bool	check_marks(char *marks)
{
	char	a;
	char	b;
	char	c;

	a = marks[0];
	b = marks[1];
	c = marks[2];
	if (a == b || a == c || b == c)
		return (false);
	return (true);
}
