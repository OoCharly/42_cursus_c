#include "ft_printf.h"

char    *ft_precision_string(t_flag *f, char *s)
{
	int             len;
	char    *out;

	len = ft_strlen(s);
	if (f->precision >= 0 && f->precision < len)
	{
		if (!(out = ft_strndup(s, (size_t)f->precision)))
			exit(-1);
		free(s);
	}
	else
		out = s;
	return (out);
}

char    *ft_precision_integer(t_flag *f, char *s)
{
	int             len;
	char    *tmp;
	char    *out;

	len = ft_strlen(s);
	if (f->precision == 0 && s[0] == '0' && !f->pad_0)
	{
		s[0] = f->sign_force;
		f->sign_force = '\0';
		return (s);
	}
	else if (POS(f->precision - len))
	{
		out = ft_memset(ft_strnew(f->precision - len), '0', f->precision - len);
		out = ft_strfjoin(out, s);
		if (!out)
			exit(-1);
	}
	else
		out = s;
	return (out);
}

char	*ft_integer_transform(t_flag *f, va_list ap)
{
	char	*out;
	char	*tmp;

	if (ft_strchr(INTEGER_TYPE, f->type))
	{
		out = ft_render_signed_integers(ap, f);
		if (out[0] == '-')
		{
			tmp = out;
			out = strdup(out + 1);
			free(tmp);
		}
		out = ft_precision_integer(f, out);
	}
	else
	{
		out = ft_render_unsigned_integers(ap, f);
		if (out[0] == '0')
			f->alt = 0;
		out = ft_precision_integer(f, out);
	}
	return (out);
}

char    *ft_transform(t_flag *f, va_list ap)
{
	char    *out;
	char    *tmp;

	if (f->type == '%')
		return (ft_wchar_to_string('%'));
	else if (ft_strchr(INTEGER_TYPE UINTEGER_TYPE, f->type))
		return (ft_integer_transform(f, ap));
	else if (ft_strchr(STRING_TYPE, f->type))
	{
		out = ft_render_string(ap, f, (ft_tolower(f->type) == 'c') ? 1 : 0);
		out = ft_precision_string(f, out);
		return (out);
	}
	else if (ft_strchr(DOUBLE_TYPE, f->type))
	{
		exit(-1);
	}
	return (NULL);
}
