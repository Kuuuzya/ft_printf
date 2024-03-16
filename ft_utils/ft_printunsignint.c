/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsignint.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 17:17:09 by skuznets          #+#    #+#             */
/*   Updated: 2024/03/16 19:36:00 by skuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printunsignint(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_printunsignint(n / 10);
	ft_putchar((n % 10) + '0');
	return (count + 1);
}
