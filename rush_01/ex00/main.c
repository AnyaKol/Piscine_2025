/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timurray <timurray@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 10:47:14 by timurray          #+#    #+#             */
/*   Updated: 2025/01/26 18:07:12 by timurray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		check_input(char *input);
int		input_is_valid(char *input);
int		solution(char grid[4][4], int count, int avail[8][4], char *views);
void	write_error(void);
void	print_grid(char grid[4][4]);
void	fill_array(int grid[8][4]);
void	remove_spaces(char *views, char *input);

int	main(int argc, char **argv)
{	
	char	views[17];
	char	grid[4][4];
	int		avail[8][4];

	if (argc != 2)
		write_error();
	else
	{
		remove_spaces(views, argv[1]);
		if (input_is_valid(argv[1]) == 0 || check_input(views) == 0)
		{
			write_error();
			return (0);
		}
		fill_array(avail);
		if (solution(grid, 0, avail, views) == 1)
			print_grid(grid);
		else
			write_error();
	}
	return (0);
}

void	remove_spaces(char *views, char *input)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	while (input[i] != '\0')
	{
		c = input[i];
		if (c >= '1' && c <= '4')
			views[j++] = c;
		i++;
	}
	views[j] = '\0';
}

void	fill_array(int grid[8][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 8)
	{
		j = 0;
		while (j < 4)
		{
			grid[i][j] = 1;
			j++;
		}
		i++;
	}
}
