/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moud <mel-moud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:34:04 by mel-moud          #+#    #+#             */
/*   Updated: 2024/11/28 11:44:26 by mel-moud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long nb)
{
	int	len;

	len = 0;
	if (nb == -2147483648)
	{
		len += ft_putchar('-');
		len += ft_putnbr(2147483648);
	}
	else if (nb < 0)
	{
		len += ft_putchar('-');
		nb = -nb;
		len += ft_putnbr(nb);
	}
	else if (nb > 9)
	{
		len += ft_putnbr(nb / 10);
		len += ft_putnbr(nb % 10);
	}
	else
		len += ft_putchar(nb + 48);
	return (len);
}
