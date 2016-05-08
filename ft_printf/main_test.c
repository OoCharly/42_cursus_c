#include <stdint.h>
#include <limits.h>
#include <stdio.h>


int	main()
{
	long	a;
	int	i;
	short	c;

	c = 184;
	c = c >> 8;
	i = 47483648; 
	a = LONG_MAX;
	return (printf("%d", size_bin(c)));
}
