#include "ft_printf.c"
#include "ft_strfuncs.c"
#include <stdio.h>
int main(void)
{
	(void)ft_printf("%p\n",(void*)65);
	printf("REALPRINT %p\n",(void*)65);
	return (0);
}
