#include "ft_printf.h"
#include <stdio.h>

int	main (void)
{
	char *str = NULL;
	
	printf("%i ", printf(" %i %d %s %c %c %% %u %x %X %p \n", 2147483647, -2147483647, "Escola", '4', '2', 2147483647, 255, 255, str));
	ft_printf("%i ", ft_printf(" %i %d %s %c %c %% %u %x %X %p \n", 2147483647, -2147483647, "Escola", '4', '2', 2147483647, 255, 255, str));
}
