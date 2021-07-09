#include <stdio.h>
#include <unistd.h>
#include "../includes/printf.h"
int main(void)
{
	printf("%i", printf("%i %s qwe%%\n", 213123213123, "qweqwewqeqwe") == printf("%i %s qwe%%\n", 213123213123, "qweqwewqeqwe"));
	return (0);
}
