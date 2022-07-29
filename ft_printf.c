/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 18:55:37 by armaxima          #+#    #+#             */
/*   Updated: 2021/11/05 18:56:17 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putnbr16low_len(unsigned long long n)
{
	const char		base[] = "0123456789abcdef";
	static size_t	len;

	len = 0;
	while (n >= 16)
	{
		ft_putnbr16low_len(n / 16);
		break ;
	}
	len += ft_putchar_len(base[n % 16]);
	return (len);
}

size_t	ft_putnbr16high_len(unsigned long long n)
{
	const char		base[] = "0123456789ABCDEF";
	static size_t	len;

	len = 0;
	while (n >= 16)
	{
		ft_putnbr16high_len(n / 16);
		break ;
	}
	len += ft_putchar_len(base[n % 16]);
	return (len);
}

size_t	ft_putponter_len(unsigned long long n)
{
	size_t	len;

	len = 0;
	len += ft_putstr_len("0x");
	len += ft_putnbr16low_len(n);
	return (len);
}

size_t	ft_print_ar(const char *str, size_t i, va_list ar)
{
	if (str[i] == 'c')
		return (ft_putchar_len((char) va_arg(ar, int)));
	if (str[i] == 's')
		return (ft_putstr_len(va_arg(ar, char *)));
	if (str[i] == 'p')
		return (ft_putponter_len(va_arg(ar, unsigned long long)));
	if (str[i] == 'd')
		return (ft_putnbr_len(va_arg(ar, int)));
	if (str[i] == 'u')
		return (ft_putnbru_len(va_arg(ar, unsigned int)));
	if (str[i] == 'i')
		return (ft_putnbr_len(va_arg(ar, int)));
	if (str[i] == 'x')
		return (ft_putnbr16low_len(va_arg(ar, unsigned int)));
	if (str[i] == 'X')
		return (ft_putnbr16high_len(va_arg(ar, unsigned int)));
	if (str[i] == '%')
		return (ft_putchar_len('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	size_t	len_write;
	va_list	ar;

	if (!str)
		return (0);
	i = 0;
	len_write = 0;
	va_start(ar, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] != '\0')
			len_write += ft_print_ar(str, ++i, ar);
		else
		{
			write(1, &str[i], 1);
			len_write++;
		}
		i++;
	}
	va_end(ar);
	return (len_write);
}
