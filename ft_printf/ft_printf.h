/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moud <mel-moud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 13:43:33 by mel-moud          #+#    #+#             */
/*   Updated: 2024/11/28 11:49:13 by mel-moud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_putchar(char c);
int		ft_printf(const char *s, ...);
int		ft_putnbr_base(unsigned long nbr, char *base);
int		ft_putnbr(long nb);
int		ft_putstr(char *str);
size_t	ft_strlen(const char *s);

#endif