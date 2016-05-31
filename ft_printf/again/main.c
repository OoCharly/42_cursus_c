#include "ft_printf.h"
#include <wchar.h>
#include <locale.h>

int main()
{
	wchar_t	oloy;
	char	*yolo;
	setlocale(LC_ALL, "");

	oloy = L'™';
	yolo = ft_wchar_to_string(oloy);
	write(1, yolo, 2);
	write(1, "\n", 1);
	ft_printf("%hhb %hhb %hhb\n", yolo[0], yolo[1], yolo[2]);
	printf("%d %hhu %hhu\n", (int)oloy, yolo[0], yolo[1]);
	printf("%u %u %u\n", oloy >> 6,oloy, ~((oloy << 26) >> 26));
	ft_printf("{%30S}", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");

	return (0);
}
