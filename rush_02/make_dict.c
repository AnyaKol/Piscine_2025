/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:50:27 by akolupae          #+#    #+#             */
/*   Updated: 2025/02/02 20:00:49 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include <stdlib.h>
#include <stdio.h>

int		count_entries(char *file_ptr);
t_bool	make_dict(char **file_ptr, struct s_entry **dict_ptr);
void	write_error(void);

t_bool	make_dict(char **file_ptr, struct s_entry **dict_ptr)
{
	int	entries;
	int	i;
	int	file_i;

	entries = count_entries(*file_ptr);
	*dict_ptr = (struct s_entry *)malloc(entries * sizeof(struct s_entry) + 1);
	if (*dict_ptr == NULL)
	{
		write_error();
		exit(1);
		return (FALSE);
	}
	i = 0;
	file_i = 0;
	(*dict_ptr)[i].key = &(*file_ptr)[0];
	while ((*file_ptr)[file_i + 1] != '\0')
	{
		if ((*file_ptr)[file_i] == ':')
		{
			(*file_ptr)[file_i] = '\0';
			(*dict_ptr)[i].value = &(*file_ptr)[file_i + 1];
			i++;
		}
		else if ((*file_ptr)[file_i] == '\n')
		{
			(*file_ptr)[file_i] = '\0';
			(*dict_ptr)[i].key = &(*file_ptr)[file_i + 1];
		}
		file_i++;
	}
	return (TRUE);
}

int	count_entries(char *file_ptr)
{
	int	i;
	int	entries;

	i = 0;
	entries = 0;
	while (file_ptr[i] != '\0')
	{
		if (file_ptr[i] == '\n')
			entries++;
		i++;
	}
	return (entries);
}
