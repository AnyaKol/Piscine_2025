/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:50:27 by akolupae          #+#    #+#             */
/*   Updated: 2025/02/04 16:50:37 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_error(void)
{
	write(2, "Error\n", 6);
}

void	write_map_error(void)
{
	write(2, "map error\n", 10);
}
