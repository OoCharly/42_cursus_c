#include <stdint.h>
#include <limits.h>
#include <stdio.h>


int	main()
{
	uintmax_t	u;
	intmax_t	s;

	s = INTMAX_MIN;
	u = 0;
	u -= s;
	printf("%jd\n", s);
	printf("%ju\n", u);
	return (0);
}
