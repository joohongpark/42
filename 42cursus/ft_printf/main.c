#include "ft_printf.h"

int main(void)
{
	int i = 0;
	/*
	printf("  printf pointer : %-18p\n", &i);
	ft_printf("  printf pointer : %p\n", &i);
	*/
	i = ft_printf("[%-10.0u]\n" , 10);
	i += ft_printf("[%10.0u]\n" , 10);
	ft_printf("retnrn value : %d\n", i);
	return (0);
}
