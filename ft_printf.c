/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:24:47 by skuznets          #+#    #+#             */
/*   Updated: 2024/01/27 18:30:33 by skuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print(va_list params, const char *format, int i)
{
	int	count;
	
	count = 0;
	if (format[i] == 'd' || format[i] == 'i')
		count += ft_printnumber(va_arg(params, int));
	else if (format[i] == 'c')
		count += ft_putchar(va_arg(params, int));
	else if (format[i] == 's')
		count += ft_printstring(va_arg(params, char*));
	else if (format[i] == '%')
		count += ft_printpercent();
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int i;
	int count;
	va_list params;

	i = 0;
	count = 0;
	va_start(params, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_print(params, format, i);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(params);
	return (count);
}

// int main()
// {
// 	ft_printf("%c\n%d\n%d\n", 'a', 5, 42);
// 	ft_printf("%s", "Hello, World!");
// 		return (0);
// }