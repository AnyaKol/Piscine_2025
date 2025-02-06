/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:30:00 by akolupae          #+#    #+#             */
/*   Updated: 2025/01/27 20:50:42 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_space(char *str);

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (check_space(str + i) == 1)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	result = result * sign;
	return (result);
}

int	check_space(char *str)
{
	if (*str == ' ' || *str == '\f' || *str == '\n')
		return (1);
	else if (*str == '\r' || *str == '\t' || *str == '\v')
		return (1);
	return (0);
}
