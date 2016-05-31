/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstring_to_string.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 10:15:05 by cdesvern          #+#    #+#             */
/*   Updated: 2016/05/31 19:09:03 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_wstring_to_string(wchar_t *s)
{
	char	*out;
	char	*tmp;
	char	*pmt;
	int		i;

	i = 0;
	tmp = NULL;
	while (s[i])
	{
		out = ft_wchar_to_string((int)s[i]);
		pmt = ft_strjoin(tmp, out);
		if (tmp)
			free(tmp);
		tmp = pmt;
		free(out);
		i++;
	}
	return (tmp);
}
