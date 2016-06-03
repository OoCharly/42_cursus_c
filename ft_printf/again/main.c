/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 22:41:53 by cdesvern          #+#    #+#             */
/*   Updated: 2016/06/03 20:26:38 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <wchar.h>
#include <locale.h>

int main()
{
	wchar_t	*p;

	setlocale(LC_ALL, "");
	p = L"coucorüu";
	printf("pf |%#o\n", 0);
	return (ft_printf("ft |%#o\n", 0));
}
