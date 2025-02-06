/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 15:32:47 by akolupae          #+#    #+#             */
/*   Updated: 2025/01/19 16:28:19 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_number(char *buf_number, int a, int b);

void	ft_print_comb2(void)
{
	int		a;
	int		b;
	char	buf_number[5];

	a = 0;
	buf_number[2] = ' ';
	while (a <= 98)
	{
		buf_number[0] = a / 10 + '0';
		buf_number[1] = a % 10 + '0';
		b = a + 1;
		while (b <= 99)
		{
			buf_number[3] = b / 10 + '0';
			buf_number[4] = b % 10 + '0';
			write_number(&buf_number[0], a, b);
			b++;
		}
		a++;
	}
}

void	write_number(char *buf_number, int a, int b)
{
	write(1, buf_number, 5);
	if (a != 98 || b != 99)
	{
		write(1, ", ", 2);
	}
}
