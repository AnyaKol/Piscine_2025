/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:19:58 by akolupae          #+#    #+#             */
/*   Updated: 2025/02/02 20:01:33 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "types.h"

t_bool	open_file(int *dict_id);
t_bool	read_file(int *dict_id, char **file_ptr);
t_bool	make_dict(char **file_ptr, struct s_entry **dict_ptr);
void	write_error(void);
void	clear_arr(char *ptr);

int	main(int argc, char **argv)
{
	int		dict_id;
	char	*file_ptr;
	struct s_entry	*dict_ptr;
	(void)	argc;
	(void)	argv;

	if (!open_file(&dict_id))
		return (0);
	if (read_file(&dict_id, &file_ptr) == 0)
		return (0);
	make_dict(&file_ptr, &dict_ptr);
	if (close(dict_id) < 0)
	{
		write_error();
		exit(1);
	}
	free(file_ptr);
	free(dict_ptr);
	return (0);
}

t_bool	open_file(int *dict_id)
{
	int	id;

	id = open("numbers.dict", O_RDONLY);
	
	if (id < 0)
	{
		write_error();
		exit(1);
		return (FALSE);
	}
	*dict_id = id;
	return (TRUE);
}

t_bool	read_file(int *dict_id, char **file_ptr)
{
	int		bytes_read;
	char	temp_ptr[100];
	int		bytes;

	bytes_read = 0;
	bytes = 1;
	while(bytes > 0)
	{
		bytes = read(*dict_id, temp_ptr, 100);
		if (bytes < 0)
			return (FALSE);
		bytes_read = bytes_read + bytes;
	}
	*file_ptr = (char *)malloc((bytes_read + 1) * sizeof(char));
	if (*file_ptr == NULL)
	{
		write_error();
		exit(1);
		return (FALSE);
	}
	if (close(*dict_id) < 0)
	{
		write_error();
		exit(1);
	}
	open_file(dict_id);
	bytes = read(*dict_id, *file_ptr, bytes_read);
	if (bytes < 0)
		return (FALSE);
	(*file_ptr)[bytes_read] = '\0';
	return (TRUE);
}
