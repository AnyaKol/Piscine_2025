/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:27:05 by akolupae          #+#    #+#             */
/*   Updated: 2025/01/29 12:57:08 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	binary_search(int low, int high, int target);

int	ft_sqrt(int nb)
{
	int	result;

	if (nb < 0)
		return (0);
	result = binary_search(1, nb, nb);
	return (result);
}

int	binary_search(int low, int high, int target)
{
	int	mid;
	int	result;

	mid = (low + high) / 2;
	if (mid * mid == target)
		return (mid);
	while (high > low)
	{
		if (mid * mid > target)
		{
			result = binary_search(low, mid - 1, target);
			return (result);
		}
		else
		{
			result = binary_search(mid + 1, high, target);
			return (result);
		}
	}
	return (0);
}
