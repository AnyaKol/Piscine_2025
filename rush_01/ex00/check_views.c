/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_views.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timurray <timurray@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:24:37 by akolupae          #+#    #+#             */
/*   Updated: 2025/01/26 18:09:10 by timurray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_goal(char *row, int goal);
int	check_views(char *row, int left, int right);

int	check_views(char *row, int left, int right)
{
	char	reverse[4];
	int		i;

	i = 0;
	while (i <= 3)
	{
		reverse[i] = row[3 - i];
		i ++;
	}
	if (check_goal(row, left) && check_goal(reverse, right))
	{
		return (1);
	}
	return (0);
}

int	check_goal(char *row, int goal)
{
	int	i;
	int	box;
	int	views;

	i = 0;
	box = row[0];
	views = 1;
	while (i <= 3)
	{
		if (row[i] > box)
		{
			views++;
			box = row[i];
		}
		i++;
	}
	if (views == goal)
	{
		return (1);
	}
	return (0);
}
