while (!ft_strchr(FORMAT_LIST, *str))
{
	if (*str == '#')
		flag->alt = 1;
	else if (*str == '+')
		flag->sign_force = '+';
	else if (*str == ' ')
	{
		if (!flag->sign_force)
			flag->sign_force = ' ';
	}
	else if (*str == '0')
		flag->pad_0 = 1;
	else if (*str == '-')
		flag->pad_left = 1;
	else if (isnum(*str))
	{
		if (!flag->precision)
			flag->precision = ft_atoi(str);
	}
	else
		return ;
	str++;
}
