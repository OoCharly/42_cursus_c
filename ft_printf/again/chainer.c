
#include "ft_printf.h"

char	*concat_full(t_list *list)
{
	char	*out;
	t_list	tmp;

	if (!(out = ft_memalloc(ft_lstsumsize(list) + 1)))
		return (NULL);
	tmp = list;
	while (tmp)
	{
		ft_strcat(out, (const char*)tmp->data);
		tmp = tmp->next;
	}
	return (out);
}

char	*ft_transform(t_flag *flag, va_list ap)
{
	char	*out;

	if (ft_strchr(INTEGER_TYPE, flag->type))
		out = ft_render_integers(ap, flag);
	else if (ft_strchr(STRING_TYPE, flag->type))
		out = ft_render_string(ap, flag, (tolower(fmt[n]) == 'c') ? 1 : 0);
	else if (ft_strchr(DOUBLE_TYPE, flag->type))
		out = ft_render_doubles(ap, flag);
	return (out);
}

char	*ft_format_precision(int p, char *s)
{
	int		len;
	char	*tmp;
	char	*out;

	len = ft_strlen(s);
	if (p == 0 && s[0] == '0')
	{
		free(s);
		return (ft_strnew(0));
	}
	tmp = ft_memset(ft_strnew(p - len), '0', p - len);
	out = ft_strjoin(tmp, s);
	if (tmp)
		free(tmp);
	free(s);
	return (out);
}

char	*ft_format_padding(t_flag *flag, char *s)
{
	int		len;
	char	*tmp;
	char	*out;
	char	c;

	c = (flag->pad_0) ? '0' : ' ';
	len = ft_strlen(s);
	if (flag->fw > len)
	{
		tmp = ft_memset(ft_strnew(flag->fw - len), c, flag->fw - len);
		if (flag->pad_left)
			out = ft_strjoin(s, tmp);
		else
			out = ft_strjoin(tmp, s);
		if (tmp)
			free(tmp);
		free(s);
	}
	return (out);
}

char	*ft_alt_format(char *s, char type)
{
	char	*out;

	if (type == 'o' || type == 'O')
	{
		out = ft_strjoin("0", s);
		free(s);
	}
	else if (type == 'x' || type == 'X' || type == 'p')
	{
		out = ft_strjoin("0x", s);
		free(s);
	}
	return (out);
}

void	ft_process(t_flag *flag, t_list **lst, va_list ap)
{
	char	*out;

	if (!(out = ft_transform(flag, ap)))
		exit(-1);
	if (flag->precision)
	{
		if (!(out = ft_format_precision(flag->precision, out)))
			exit(-1);
	}
	if (flag->alt)
	{
		if (!(out = ft_alt_format(out, flag->type)))
			exit(-1);
	}
	if (!(out = ft_format_padding(flag, out)))
		exit(-1);
	ft_lstadd_end(lst, ft_create_node(out, ft_strlen(out) + 1));
}
