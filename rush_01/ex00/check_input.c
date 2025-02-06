/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timurray <timurray@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 12:56:46 by akolupae          #+#    #+#             */
/*   Updated: 2025/01/26 18:09:07 by timurray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_input(char *input);

int	check_input(char *input)
{
	int	i;
	int	views_sum;

	i = 0;
	while (i <= 11)
	{
		if (i == 4)
		{
			i = 8;
		}
		views_sum = input[i] + input[i + 4] - 96;
		if (views_sum < 3 || views_sum > 5)
		{
			return (0);
		}
		i++;
	}
	return (1);
}
