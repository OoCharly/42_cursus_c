/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stdargc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 15:13:07 by cdesvern          #+#    #+#             */
/*   Updated: 2016/03/31 17:11:24 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

void	yolo(char *fmt, ...)
{
	va_list	ap;
	void	*a;

	va_start(ap, fmt);
	a = va_arg(ap, void*);
	va_end(ap);
	printf("--->%s\n", a);
}

int	main()
{
	t_type	a;

	a.ll = 1234567890123456; 
	yolo("abc", "abc");
	printf("\n %i \n", a.i);
}
