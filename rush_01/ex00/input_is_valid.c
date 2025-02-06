/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_is_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timurray <timurray@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:12:40 by akolupae          #+#    #+#             */
/*   Updated: 2025/01/26 18:09:14 by timurray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	input_is_valid(char *input);

int	input_is_valid(char *input)
{
	int	i;

	i = 0;
	while (i < 30)
	{
		if (input[i] < '1' || input[i] > '4' || input[i + 1] != 32)
		{
			return (0);
		}
		i = i + 2;
	}
	if (input[i] < '1' || input[i] > '4' || input[i + 1] != '\0')
	{
		return (0);
	}
	return (1);
}
