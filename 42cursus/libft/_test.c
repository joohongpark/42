#include "libft.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
    char a[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    ft_memmove(a, a + 1, 9);
    for (int i = 0; i < 10; i++)
        printf("%c ", a[i]);
    return (0);
    
}