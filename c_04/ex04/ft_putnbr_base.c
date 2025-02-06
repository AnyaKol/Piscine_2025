/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:30:42 by akolupae          #+#    #+#             */
/*   Updated: 2025/01/28 16:12:02 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_base(int nbr, char *base)
{
	int	i;
	int	digit;

	i = 0;
	while (base[i] != '\0')
	{
		i++;
	}
	if (i < 2)
	{
		return ;
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr > i)
	{
		ft_putnbr_base(nbr / i, base);
	}
	digit = nbr % i;
	write(1, &base[digit], 1);
}
