/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 18:55:40 by armaxima          #+#    #+#             */
/*   Updated: 2021/11/05 18:56:35 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
size_t	ft_print_ar(const char *str, size_t i, va_list ar);
size_t	ft_putponter_len(unsigned long long n);
size_t	ft_putnbr16high_len(unsigned long long n);
size_t	ft_putnbr16low_len(unsigned long long n);
size_t	ft_putchar_len(char c);
size_t	ft_strlen(char	*str);
size_t	ft_putstr_len(char	*str);
size_t	ft_putnbr_len(int n);
size_t	ft_putnbru_len(unsigned int n);

#endif
