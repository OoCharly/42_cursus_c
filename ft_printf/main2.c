#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

int	main()
{
	printf("sizes:\n");
	printf("\tsigned char\t\t%lu\n", sizeof(signed char));
	printf("\tunsigned char\t\t%lu\n", sizeof(unsigned char));
	printf("\tshort\t\t\t%lu\n", sizeof(short));
	printf("\tunsigned short\t\t%lu\n", sizeof(unsigned short));
	printf("\tint\t\t\t%lu\n", sizeof(int));
	printf("\tlong\t\t\t%lu\n", sizeof(long));
	printf("\tlong long\t\t%lu\n", sizeof(long long));
	printf("\tunsigned long\t\t%lu\n", sizeof(unsigned long));
	printf("\tunsigned long long\t%lu\n", sizeof(unsigned long long));
	printf("\tintmax_t\t\t%lu\n", sizeof(intmax_t));
	printf("\tuintmax_t\t\t%lu\n", sizeof(uintmax_t));
	printf("\tptrdiff_t\t\t%lu\n", sizeof(ptrdiff_t));
	printf("\tsize_t\t\t\t%lu\n", sizeof(size_t));
	printf("\tssize_t\t\t\t%lu\n", sizeof(ssize_t));
	printf("\twchar_t\t\t\t%lu\n", sizeof(wchar_t));
	return (0);
}
