/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_stdin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwong <cwong@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:33:42 by cwong             #+#    #+#             */
/*   Updated: 2025/02/05 16:33:51 by cwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

void	ft_process_buffer(char *buffer, int *line_start, int *end, int *i)
{
	int	j;

	j = *line_start;
	while (j < *i)
	{
		if (buffer[j] == '\n' || (j >= 2 && buffer[j - 2] == 'E'
				&& buffer[j - 1] == 'N' && buffer[j] == 'D'))
		{
			write(1, buffer + *line_start, j - *line_start + 1);
			if (j >= 2 && buffer[j - 2] == 'E' && buffer[j - 1] == 'N'
				&& buffer[j] == 'D')
			{
				*end = 1;
				return ;
			}
			*line_start = j + 1;
		}
		j++;
	}
}

void	ft_shift_buffer(char *buffer, int *i, int *line_start)
{
	int	k;
	int	remaining;

	remaining = *i - *line_start;
	if (remaining > 0)
	{
		k = 0;
		while (k < remaining)
		{
			buffer[k] = buffer[*line_start + k];
			k++;
		}
		*i = remaining;
		*line_start = 0;
	}
	else
	{
		*i = 0;
		*line_start = 0;
	}
}

void	ft_read_from_stdin(void)
{
	char	buffer[1024];
	ssize_t	bytes_read;
	int		end_detected;
	int		i;
	int		line_start;

	end_detected = 0;
	i = 0;
	line_start = 0;
	write(1, "Enter filename(s) (type 'END' to finish):\n", 42);
	bytes_read = read(0, buffer + i, sizeof(buffer) - 1 - i);
	while (bytes_read > 0)
	{
		i += bytes_read;
		buffer[i] = '\0';
		ft_process_buffer(buffer, &line_start, &end_detected, &i);
		if (end_detected)
			break ;
		if (i == sizeof(buffer) - 1)
			ft_shift_buffer(buffer, &i, &line_start);
		bytes_read = read(0, buffer + i, sizeof(buffer) - 1 - i);
	}
	if (bytes_read == -1)
		write(1, "map error\n", 6);
}
