/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moud <mel-moud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:21:35 by mel-moud          #+#    #+#             */
/*   Updated: 2024/11/28 11:50:48 by mel-moud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
	{
		len += write(1, &str[i], 1);
		i++;
	}
	return (len);
}
