#include "ex02/ft_swap.c"
#include <stdio.h>

void	print_array(int* tab_ptr, int tab_size);

int main()
{
	//ex07
	/*
	int	my_tab[] = {1, 2, 3, 4, 5, 6, 7};
	int	tab_size = 7;
	int* tab_ptr = &my_tab[0];

	printf("Array before: ");
	print_array(tab_ptr, tab_size);
	printf("\n");
	ft_rev_int_tab(tab_ptr, tab_size);
	printf("\nArray after: ");
	print_array(tab_ptr, tab_size);
	*/
	//ex02
	
	int a = 123;
	int b = 10;
	int* a_ptr = &a;
	int* b_ptr = &b;
	ft_swap(a_ptr, b_ptr);
	printf("Result: %d, %d", a, b);
	
	//ex03-ex04
	/*
//	int a = 123;
//	int b = 10;
	int c = 123;
	int d = 10;
	int* c_ptr = &c;
	int* d_ptr = &d;
//	ft_div_mod(a, b, c_ptr, d_ptr);
	ft_ultimate_div_mod(c_ptr, d_ptr);
	printf("Result: %d, %d", c, d);
	*/
//ex05-ex06
	/*	
	char src_str[] = "Hello";
	char* str = &src_str[0];
//	ft_putstr(str);
	ft_strlen(str);
	printf("%d", ft_strlen(str));
	*/
	/*
	char src_str[] = "Hello, World!";
	char dest_str[30];
	unsigned int n = 5;
	char* src = &src_str[0];
	char* dest = &dest_str[0];

	ft_strncpy(dest, src, n);
	printf("%s\n%s", src_str, dest_str);
	*/
	
	return 0;
}

void	print_array(int* tab_ptr, int tab_size)
{
	int	i = 0;
	while (i < tab_size)
	{
		printf("%d", *(tab_ptr + i));
		i++;
	}
}
