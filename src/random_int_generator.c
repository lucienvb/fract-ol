#include <stdio.h>

unsigned int	random_generator(unsigned int *x, unsigned int *y, unsigned int *z)
{
	unsigned int	t;

	*x ^= *x << 16;
	*x ^= *x >> 5;
	*x ^= *x << 1;
	t = *x;
	*x = *y;
	*y = *z;
	*z = t ^ *x ^ *y;
	return (*z);
}

int	main(void)
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	z;
	int				random_number1;
	int				random_number2;

	x = 123456789;
	y = 362436069;
	z = 521288629;
	random_number1 = random_int_generator(&x, &y, &z) % 30 + 1;
	random_number2 = random_int_generator(&x, &y, &z) % 30 + 1;
	printf("Random number: %d\n", random_number1);
	printf("Random number: %d\n", random_number2);
	return (0);
}
