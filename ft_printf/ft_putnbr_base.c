/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moud <mel-moud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:46:12 by mel-moud          #+#    #+#             */
/*   Updated: 2024/11/27 14:24:06 by mel-moud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned long nbr, char *base)
{
	int	len_b;
	int	len;

	len = 0;
	len_b = ft_strlen(base);
	if (nbr >= (unsigned int)len_b)
		len += ft_putnbr_base(nbr / len_b, base);
	len += ft_putchar(base[nbr % len_b]);
	return (len);
}
