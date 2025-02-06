/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 11:44:28 by akolupae          #+#    #+#             */
/*   Updated: 2025/01/19 13:12:38 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	ft_rev_int_tab(int *tab, int size)
{
	int	temp;
	int	counter;
	int	*left;
	int	*right;

	counter = 0;
	while (counter < size / 2)
	{
		left = tab + counter;
		right = tab + size - 1 - counter;
		temp = *left;
		*left = *right;
		*right = temp;
		counter++;
	}
}
