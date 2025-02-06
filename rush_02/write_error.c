/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:50:27 by akolupae          #+#    #+#             */
/*   Updated: 2025/02/02 17:06:57 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_error(void);
void	write_dict_error(void);

void	write_error(void)
{
	write(1, "Error\n", 6);
}

void	write_dict_error(void)
{
	write(1, "Dict Error\n", 11);
}
