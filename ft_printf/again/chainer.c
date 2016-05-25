
#include "ft_printf.h"

char	*ft_transform(t_flag *f, va_list ap)
{
	char	*out;
	char	*tmp;

	if (f->type == '%')
		out = ft_wchar_to_string('%');
	else if (ft_strchr(INTEGER_TYPE, f->type))
	{
		out = ft_render_signed_integers(ap, f);
		if (out[0] == '-')
		{
			f->sign_force = '-';
			tmp = out;
			out = strdup(out + 1);
			free(tmp);
		}
	}
	else if (ft_strchr(UINTEGER_TYPE, f->type))
	{
		out = ft_render_unsigned_integers(ap, f);
		if (out[0] == '0')
			f->alt = 0;
	}
	else if (ft_strchr(STRING_TYPE, f->type))
		out = ft_render_string(ap, f, (ft_tolower(f->type) == 'c') ? 1 : 0);
//	else if (ft_strchr(DOUBLE_TYPE, f->type))
//		out = ft_render_doubles(ap, f);
	return (out);
}

char	*ft_format_precision(t_flag *f, char *s)
{
	int		len;
	char	*tmp;
	char	*out;

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

char	*ft_format_padding(t_flag *flag, char *s)
{
	int		len;
	char	*out;
	char	c;

	c = (flag->pad_0) ? '0' : ' ';
	if (flag->sign_force && !flag->pad_0)
		s = ft_strfjoin(ft_wchar_to_string(flag->sign_force), s);
	len = ft_strlen(s);
	if (flag->fw > len)
	{
		if (!(out = ft_memset(ft_strnew(flag->fw - len), c, flag->fw - len)))
			exit(-1);
		if (flag->pad_left)
			out = ft_strfjoin(s, out);
		else
			out = ft_strfjoin(out, s);
		if (!out)
			exit(-1);
		if (flag->pad_0 && ft_strchr(INTEGER_TYPE, flag->type))
			out[0] = flag->sign_force;
	}
	else
		out = s;
	return (out);
}

char	*ft_alt_format(char *s, t_flag *f)
{
	char	*out;

	if ((f->type == 'o' || f->type == 'O') && !f->precision)
	{
		out = ft_strjoin("0", s);
		free(s);
	}
	else if (f->type == 'x' || f->type == 'X' || f->type == 'p')
	{
		if (f->pad_0 && f->precision <= 0 && f->fw)
		{
			f->fw = POS(f->fw - 2);
			out = ft_format_padding(f, s);
			s = out;
		}
		out = ft_strjoin("0x", s);
		free(s);
	}
	else
		out = s;
	return (out);
}

char	*ft_process(t_flag *flag, t_list **lst, va_list ap)
{
	char	*out;

	stat_flag(flag);
	if (!(out = ft_transform(flag, ap)))
		exit(-1);
	if (!(out = ft_format_precision(flag, out)))
		exit(-1);
	if (flag->alt)
	{
		if (!(out = ft_alt_format(out, flag)))
			exit(-1);
	}
	if (flag->type == 'X')
		ft_capitalize(out);
	if (!(out = ft_format_padding(flag, out)))
		exit(-1);
	return (out);
}
