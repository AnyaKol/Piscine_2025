#include <stdio.h>
#include <stdlib.h>
//#include "c_04/ex00/ft_strlen.c"
//#include "c_04/ex01/ft_putstr.c"
//#include "c_04/ex02/ft_putnbr.c"
//#include "c_04/ex03/ft_atoi.c"
#include "c_04/ex04/ft_putnbr_base.c"

int main(void)
{
//ex00-ex01
/*
    char str[] = "Hello";
    //printf("%d", ft_strlen(str));
    ft_putstr(str);
*/
//ex02
/*
	int nb = -2147483648;
	//int nb = 0;
	//int nb = 345;
	ft_putnbr(nb);
*/
//ex03
/*
	char str[] = "   \f  +-+--123safe123";	
	printf("Atoi: %d\n", atoi(str));
	printf("My func: %d", ft_atoi(str));
*/
//ex04

  //char base[] = "01";
  char base[] = "poneyvif";//24660 = ipony
  //char base[] = "0123456789";
  //char base[] = "0123456789ABCDEF";//-38475 = -964B

  ft_putnbr_base(24660, base);

    return (0);
}
