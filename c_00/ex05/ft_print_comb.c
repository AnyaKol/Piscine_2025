/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:23:33 by akolupae          #+#    #+#             */
/*   Updated: 2025/01/19 15:11:58 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_number(char *buf_number);

void	ft_print_comb(void)
{
	int		a;
	int		b;
	int		c;
	char	buf_number[3];

	a = 0;
	while (a <= 7)
	{
		buf_number[0] = a + '0';
		b = a + 1;
		while (b <= 8)
		{
			buf_number[1] = b + '0';
			c = b + 1;
			while (c <= 9)
			{
				buf_number[2] = c + '0';
				write_number(&buf_number[0]);
				c++;
			}
			b++;
		}
		a++;
	}
}

void	write_number(char *buf_number)
{
	write(1, buf_number, 3);
	if (buf_number[0] != '7' || buf_number[1] != '8' || buf_number[2] != '9')
	{
		write(1, ", ", 2);
	}
}
