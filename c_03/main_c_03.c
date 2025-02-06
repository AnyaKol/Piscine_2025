//main for C 03
#include "/home/akolupae/Documents/backup/c_03/ex04/ft_strstr.c"
#include <stdio.h>
#include <string.h>

int main()
{
	//ex00-ex03
	/*	
	//char src_1[5] = "ABC";
	//char dest_1[] = " DEF";
	char src_2[5] = "ABC";
	char dest_2[] = " DEF";

	//printf("Strcmp: %d\n", strcmp(&src_1[0], &src_2[0]));
	//printf("My strcmp: %d", ft_strcmp(&src_1[0], &src_2[0]));
	
	//printf("Strncmp: %d\n", strncmp(&src_1[0], &src_2[0], 2));
	//printf("My strncmp: %d", ft_strncmp(&src_1[0], &src_2[0], 2));

	//printf("Strcat: %s\n", strcat(&src_1[0], &dest_1[0]));
	//printf("My strcat: %s", ft_strcat(&src_2[0], &dest_2[0]));

	//printf("Strncat: %s\n", strncat(&src_1[0], &dest_1[0], 2));
	printf("My strncat: %s", ft_strncat(&src_2[0], &dest_2[0], 2));
	*/
	//ex04

	char src[] = "HeloHelloHello";
	char to_find[] = "abc";
	
	//printf("Strstr: %s\n", strstr(&src[0], &to_find[0]));
	printf("My strstr: %s", ft_strstr(&src[0], &to_find[0]));

	//ex05
	/*
	char src[] = " CD";
	char dest[5] = "AB";
	int size;

	size = ft_strlcat(dest, src, 5);
	printf("Size: %d\nString: %s", size, dest);
	*/
	return (0);
}
