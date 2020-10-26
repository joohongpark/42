#include "ft_printf.h"

int main(void)
{
	int i = 0;
	i = ft_printf("test number : %d\ntest string : %02s\ntest : %%\n", -42, "asc");
	i = ft_printf("test hex : %x\ntest hex : %X\ntest u : %u\n", 0xffffffff, 0x12345678, 0xffffffff);
	ft_printf("retnrn value : %10d\n", i);
	return (0);
}
