/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 19:23:48 by akolupae          #+#    #+#             */
/*   Updated: 2025/02/04 09:40:57 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	str_len(char *str);
char	*str_dup(char *src);

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int	i;
	struct s_stock_str	*result;

	result = (struct s_stock_str *)malloc((ac + 1) * sizeof(struct s_stock_str));
	if (!result)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		result[i].size = str_len(av[i]);
		result[i].str = av[i];
		result[i].copy = str_dup(av[i]);
	}
	result[i].str = 0;
	return (result);
}

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return(i);
}

char	*str_dup(char *src)
{
	unsigned int	i;
	char			*dest;

	i = 0;
	if (src == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		i++;
	}
	dest = (char *)malloc((i + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
