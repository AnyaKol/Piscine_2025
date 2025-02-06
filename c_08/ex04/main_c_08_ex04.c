//ex03
# include "ft_strs_to_tab.c"
# include <stdio.h>

int	main(void)
{
	char	*arr[] =
	{"Hello",
	"abc",
	"World"
	};
	struct s_stock_str	*struct_ptr;

	struct_ptr = ft_strs_to_tab(3, arr);
	//printf("%d", point.x);
	free(struct_ptr);
	return (0);
}
