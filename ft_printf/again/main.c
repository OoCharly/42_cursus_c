/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 22:41:53 by cdesvern          #+#    #+#             */
/*   Updated: 2016/06/02 19:54:49 by cdesvern         ###   ########.fr       */
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
	printf("pf |%.5S", L"œ∂ƒ©˙");
	ft_printf("ft |%.5S", L"œ∂ƒ©˙");
	return (0);
}
