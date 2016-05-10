#include "libft.h"

char	*ft_wstring_to_string(wchar_t *s)
{
	char	*out;
	char	*tmp;
	char	*pmt;

	tmp = NULL;
	while (*s)
	{
		out = ft_wchar_to_string((int)*s);
		pmt = ft_strjoin(tmp, out);
		if (tmp)
			free(tmp);
		tmp = pmt;
		free(out);
	}
	return (tmp);
}
