#include <stdarg.h>
#include <stdio.h>

void	ft_yolo_varg(char *fmt, ...)
{
	va_list	ap;
	int		a;
	
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == 's')
			printf("string %s", va_arg(ap, char*));
		fmt++;
	}
}

int	main()
{
	char *pouet;

	pouet = "yoloswag";
	ft_yolo_varg("s", pouet);
	return (0);}
