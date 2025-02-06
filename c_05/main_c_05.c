#include <stdio.h>
//#include "c_05/ex00/ft_iterative_factorial.c"
//#include "c_05/ex01/ft_recursive_factorial.c"
//#include "c_05/ex02/ft_iterative_power.c"
//#include "c_05/ex03/ft_recursive_power.c"
//#include "c_05/ex04/ft_fibonacci.c"
//#include "c_05/ex05/ft_sqrt.c"
//#include "c_05/ex06/ft_is_prime.c"
#include "c_05/ex07/ft_find_next_prime.c"

int	main(void)
{
//ex00-ex03
/*
	int nb = -3;
	int power = 3;
	//printf("Factorial of %d is %d", nb, ft_iterative_factorial(nb));
	//printf("Factorial of %d is %d", nb, ft_recursive_factorial(nb));
	printf("%d in the power of %d is %d", nb, power, ft_iterative_power(nb, power));
	//printf("%d in the power of %d is %d", nb, power, ft_recursive_power(nb, power));
*/
//ex04-ex06

	int index = -5;
	//printf("Fibonacci %d: %d", index, ft_fibonacci(index));
	//printf("Root of %d: %d", index, ft_sqrt(index));
	//printf("Is %d prime: %d", index, ft_is_prime(index));
	printf("Next prime from  %d: %d", index, ft_find_next_prime(index));

	return (0);
}
