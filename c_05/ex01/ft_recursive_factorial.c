/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:27:05 by akolupae          #+#    #+#             */
/*   Updated: 2025/01/28 18:40:39 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int	factor;

	factor = 1;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	if (nb > 2)
	{
		factor = ft_recursive_factorial(nb - 1);
		return (nb * factor);
	}
	return (nb);
}
