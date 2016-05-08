#include "libft.h"

static char	*ft_wchar_malloc(int size)
{
	if (size <= 7)
		return (ft_memalloc(sizeof(char) * 2));
	if (size <= 11)
		return (ft_memalloc(sizeof(char) * 3));
	if (size <= 16)
		return (ft_memalloc(sizeof(char) * 4));
	return (ft_memalloc(sizeof(char) * 5));
}

char		*ft_wchar_to_string(int c)
{
	char	*out;
	int	size;

	size = ft_nsize_base(c, 2);
	out = ft_wchar_malloc(size);
	if (!(c >> 7))
	{
		
