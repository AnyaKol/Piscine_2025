#include <stdio.h>
#include <stdlib.h>
//#include "c_07/ex00/ft_strdup.c"
//#include "c_07/ex01/ft_range.c"
//#include "c_07/ex02/ft_ultimate_range.c"
#include "c_07/ex03/ft_strjoin.c"

int	main(void)
{
//ex00
/*
	char	*src = "";
	char	*dest = ft_strdup(src);
	printf("%s", dest);
	free(dest);
*/
//ex01
/*
	int min = -6;
	int max = -2;
	int i = 0;
	int len = max - min;
	int *ptr = ft_range(min, max);

	while (i < len)
	{
			printf("%d", ptr[i]);
			i++;
	}
	free(ptr);
*/
//ex02
/*
	int min = -2;
	int max = 2;
	int *ptr;
	int size;
	int i = 0;

	size = ft_ultimate_range(&ptr, min, max);
	printf("%d\n", size);
	while (i < size)
	{
		printf("%d", ptr[i]);
		i++;
	}
	free(ptr);
	ptr = NULL;
*/
//ex03

	char *strs[] =
	{
	"Hello",
	"abc",
	"World"
	};
	char *ptr = ft_strjoin(3, strs, "123");

	printf("%s", ptr);
	free(ptr);

	return (0);
}
