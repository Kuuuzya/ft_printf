/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:40:02 by skuznets          #+#    #+#             */
/*   Updated: 2024/01/27 18:32:20 by skuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char* s)
{
	if (s == NULL)
		return (0);
	while (*s)
		write(1, s++, 1);
	return (ft_strlen(s));
}

int	ft_printstring(char *s)
{

	int		count;

	count = 0;
	if (s == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	else
		count += ft_putstr(s);
	return (count);
}

int	ft_printnumber(int n)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(n);
	len = ft_printstring(num);
	free(num);
	return (len);
}

int	ft_printpercent(void)
{
	write(1, "%", 1);
	return (1);
}
