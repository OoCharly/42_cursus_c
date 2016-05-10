#include <stdint.h>
#include <limits.h>
#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <stdlib.h>

int	main()
{
	long	a;
	int	i;
	short	c;

	char *l = setlocale(LC_ALL, "");
	if (l == NULL)
		printf("locale not set\n\n");
	else
		printf("set %s\n\n", l);
	c = 184;
	c = c >> 8;
	i = 9; 
	a = LONG_MAX;
	printf("%%d");
	return (0);
}
