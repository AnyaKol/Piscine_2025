/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:40:30 by akolupae          #+#    #+#             */
/*   Updated: 2025/02/03 15:52:38 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		str_len(char *str);
void	print_str(int size, char **strs, char *sep, char *ptr);
void	add_sep(char *ptr, char *sep, int *ptr_i);

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		len;
	char	*ptr;

	if (size <= 0)
		return (NULL);
	i = 0;
	len = 1;
	while (i < size)
	{
		len = len + str_len(strs[i]);
		i++;
	}
	len = len + (str_len(sep) * (size - 1));
	ptr = (char *)malloc(len * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	print_str(size, strs, sep, ptr);
	return (ptr);
}

void	print_str(int size, char **strs, char *sep, char *ptr)
{
	int	i;
	int	j;
	int	ptr_i;

	i = 0;
	j = 0;
	ptr_i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			ptr[ptr_i] = strs[i][j];
			j++;
			ptr_i++;
		}
		if (i < size - 1)
		{
			add_sep(ptr, sep, &ptr_i);
		}
		i++;
	}
	ptr[ptr_i] = '\0';
}

void	add_sep(char *ptr, char *sep, int *ptr_i)
{
	int	i;

	i = 0;
	while (sep[i] != '\0')
	{
		ptr[*ptr_i] = sep[i];
		write(1, sep + i, 1);
		i++;
		(*ptr_i)++;
	}
}

int	str_len(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}
