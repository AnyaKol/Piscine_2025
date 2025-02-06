/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:13:07 by akolupae          #+#    #+#             */
/*   Updated: 2025/02/02 14:13:10 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H
# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# include <stdio.h>//remove

void	write_error(void);
void	write_map_error(void);
void	loop_args(int *file_id, char *arg_name, char **map_str, int ***map_arr);
bool	open_file(int *file_id, char *file_name);
bool	read_file(int *file_id, char **map_str);
bool	close_file(int *file_id);
bool	map_is_valid(char **map_str);
bool	check_len(char *str, int len, int i);
bool	compare_size(char *str, int size);
bool	check_free_box(char *str, int i);
bool	make_arr(char **map_str, int ***map_arr);
int		lines_num(char *str);
int		line_len(char *str);
int		*make_row(char **map_str, int row, int len);
bool	find_marks(char *str, char *marks);
bool	check_marks(char *marks);
void	ft_find_largest_square(int **map, int row, int col, char *characters);
void	ft_allocate_result(char ***result, int row, int col);
void	ft_free_memory_char(char **grid, int row);
void	ft_free_memory_int(int **grid, int row);
void	ft_fill_map(int **map, int row, int col, int *largest);
int		ft_min(int a, int b, int c);
void	ft_find_largest(int **map, int row, int col, int largest);
void	ft_mark_square(int **map, int row, int col, int largest);
void	ft_print_result(char **result, int row, int col);
void	ft_strcpy(char *dest, char *src);
void	ft_read_from_stdin(char *files_str);

#endif
