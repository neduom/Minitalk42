/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moud <mel-moud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:31:40 by mel-moud          #+#    #+#             */
/*   Updated: 2025/03/11 21:28:52 by mel-moud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_formats(va_list args, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (format == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		len += (ft_putstr("0x") + ft_putnbr_base(va_arg(args, unsigned long),
					"0123456789abcdef"));
	else if (format == 'd' || format == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		len += ft_putnbr(va_arg(args, unsigned int));
	else if (format == 'x')
		len += ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef");
	else if (format == 'X')
		len += ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (format == '%')
		len += ft_putchar('%');
	else
		len += ft_putchar(format);
	return (len);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	va_list	lag;
	int		len;

	i = 0;
	len = 0;
	if (write(1, "", 0))
		return (-1);
	va_start(lag, s);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
		{
			len += handle_formats(lag, s[i + 1]);
			i++;
		}
		else
			len += ft_putchar(s[i]);
		i++;
	}
	va_end(lag);
	return (len);
}
