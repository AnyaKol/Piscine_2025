/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 19:20:24 by akolupae          #+#    #+#             */
/*   Updated: 2025/01/23 09:05:39 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	upcase(char *current_char);
void	lowcase(char *current_char);

char	*ft_strcapitalize(char *str)
{
	int	i;

	upcase(str);
	i = 1;
	while (str[i] != '\0')
	{
		if (str[i - 1] < '0' || (str[i - 1] > '9' && str[i - 1] < 'A')
			|| (str[i - 1] > 'Z' && str[i - 1] < 'a') || str[i - 1] > 'z')
		{
			upcase(str + i);
		}
		else
		{
			lowcase(str + i);
		}
		i++;
	}
	return (str);
}

void	upcase(char *current_char)
{
	if (*current_char >= 'a' && *current_char <= 'z')
	{
		*current_char -= 32;
	}
}

void	lowcase(char *current_char)
{
	if (*current_char >= 'A' && *current_char <= 'Z')
	{
		*current_char += 32;
	}
}
