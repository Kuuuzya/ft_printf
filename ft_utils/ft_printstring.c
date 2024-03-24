/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:53:23 by skuznets          #+#    #+#             */
/*   Updated: 2024/03/20 20:01:05 by skuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_putstr(char *s)
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
	return (ft_strlen(s));
}
