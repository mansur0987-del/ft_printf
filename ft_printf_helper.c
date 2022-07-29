/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 18:55:32 by armaxima          #+#    #+#             */
/*   Updated: 2021/11/05 18:55:34 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putchar_len(char c)
{
	write (1, &c, 1);
	return (1);
}

size_t	ft_strlen(char	*str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_putstr_len(char	*str)
{
	size_t	i;

	i = 0;
	if (!str || str == NULL)
	{
		i += ft_putstr_len("(null)");
		return (i);
	}
	while (str[i] != '\0')
	{
		ft_putchar_len(str[i]);
		i++;
	}
	return (i);
}

size_t	ft_putnbr_len(int n)
{
	size_t	len;

	len = 0;
	if (n == -2147483648)
	{
		len += ft_putstr_len("-2147483648");
		return (len);
	}
	if (n < 0)
	{
		n = -n;
		len += ft_putchar_len('-');
	}
	while (n >= 10)
	{
		len += ft_putnbr_len(n / 10);
		break ;
	}
	len += ft_putchar_len(n % 10 + '0');
	return (len);
}

size_t	ft_putnbru_len(unsigned int n)
{
	static size_t	len;

	len = 0;
	while (n >= 10)
	{
		ft_putnbru_len(n / 10);
		break ;
	}
	len += ft_putchar_len(n % 10 + '0');
	return (len);
}
