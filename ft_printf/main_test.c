#include <stdint.h>
#include <limits.h>
#include <stdio.h>


int	main()
{
	int	a;

	a = 42;
	return (printf("%010*d\n", a, 1024));
	
}
