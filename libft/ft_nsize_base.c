#include "libft.h"

int	*ft_nsize_base(uintmax_t nb, int base)
{
	int	i;

	i = 0;
	while (nb / ft_pow(base, i))
		i++;
	return (i);
}
