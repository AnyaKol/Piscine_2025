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

void	ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

void	ft_read_from_stdin(char *files_str)
{
	char	buffer[1024];
	ssize_t	bytes_read;

	bytes_read = read(0, buffer, 1023);
	if (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		ft_strcpy(files_str, buffer);
	}
	else
		write_error();
}
