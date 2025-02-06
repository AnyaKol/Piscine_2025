/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 15:32:47 by akolupae          #+#    #+#             */
/*   Updated: 2025/01/19 19:27:35 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//This is wrong

#include <unistd.h>

int		log_10(int nb);
int		calc_max_power_10(int digits);
int		check_negative(int nb);

void	ft_putnbr(int nb)
{
	int		digit_num;
	int		max_power_10;
	char	nb_char;

	nb = check_negative(nb);
	digit_num = log_10(nb);
	max_power_10 = calc_max_power_10(digit_num);
	while (max_power_10 > 0)
	{
		nb_char = nb / max_power_10 + '0';
		nb = nb % max_power_10;
		write(1, &nb_char, 1);
		max_power_10 /= 10;
	}
}

//Find how many digits in number
int	log_10(int nb)
{
	int		digit_num;

	digit_num = 0;
	while (nb / 10 > 0)
	{
		digit_num++;
		nb /= 10;
	}
	return (digit_num);
}

//Calculate max power of 10
int	calc_max_power_10(int digit_num)
{
	int		max_power_10;

	max_power_10 = 1;
	while (digit_num > 0)
	{
		max_power_10 *= 10;
		digit_num--;
	}
	return (max_power_10);
}

//Check negative if number is negative
int	check_negative(int nb)
{
	if (nb < 0)
	{
		nb = nb * (-1);
		write(1, "-", 1);
	}
	return (nb);
}
