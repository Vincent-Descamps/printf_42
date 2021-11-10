/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:24:42 by vdescamp          #+#    #+#             */
/*   Updated: 2021/11/10 16:07:02 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printf(const char *format, ...)
{
	char	*str;
	int		i;
	int		j;
	va_list	ap;

	i = 0;
	j = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			j++;
		}
		if (format[i] == '%')
		{
			i++;
			j += ft_check(format[i], ap);
		}
		i++;
	}
	va_end(ap);
	return (j);
}

int	main(void)
{
	ft_printf("blabal %s", "bjkbkjbk");
	return (0);
}
