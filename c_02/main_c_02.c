//main for C 02
#include "/home/akolupae/Documents/c_02/ex10/ft_strlcpy.c"
#include <stdio.h>
#include <string.h>

int main()
{
	//ex00-ex01, ex10
	
	char src[] = "Hello";
	char dest[10];
	//char dest_1[10];

	//printf("String with my code: %s\n", ft_strcpy(dest, src));
	//printf("String with strcpy: %s\n", strcpy(dest_1, src));

	//printf("String with my code: %s\n", ft_strncpy(dest, src, 8));
	//printf("String with strncpy: %s\n", strncpy(dest_1, src, 8));
	
	printf("Length of source: %u\n", ft_strlcpy(dest, src, 6));
	printf("%s", dest);
	
	//ex02-ex03-ex04-ex05-ex06
	/*
	char my_str[] = "sdf\nsffe";
	char* str_ptr = &my_str[0];
	//printf("Alphabetic: %d", ft_str_is_alpha(str_ptr));
	//printf("Numeric: %d", ft_str_is_numeric(str_ptr));
	//printf("Lowercase: %d", ft_str_is_lowercase(str_ptr));
	//printf("Uppercase: %d", ft_str_is_uppercase(str_ptr));
	printf("Printable: %d", ft_str_is_printable(str_ptr));
	*/
	//ex07-ex08
	/*
	char my_str[] = "HALLoZ";
	char* str_ptr = &my_str[0];
	printf("String: %s\n", str_ptr);
	//printf("Upcase: %s\n", ft_strupcase(str_ptr));
	printf("Lowcase: %s\n", ft_strlowcase(str_ptr));
	*/
	//ex09
	/*
	char my_str[] = "salut, coMment tu vaS ? 42Mots quarante-deux; cinquante+Et+un";
	char* str_ptr = &my_str[0];
	printf("String: %s\n", str_ptr);
	printf("Capitalize: %s\n", ft_strcapitalize(str_ptr));
	*/
	
	return 0;
}
