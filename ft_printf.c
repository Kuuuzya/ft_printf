/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:24:47 by skuznets          #+#    #+#             */
/*   Updated: 2024/01/27 16:43:47 by skuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int i;
	va_list params;

	i = 0;
	//va_start(params, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'd')
				ft_putnbr(va_arg(params, int));
		}
		else
			ft_putchar(format[i]);
		i++;
	}
//	va_end(params);
	return (0);
}

int main()
{
	ft_printf("%d", 42);
	return (0);
}