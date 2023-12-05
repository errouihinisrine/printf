/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ner-roui <ner-roui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:17:54 by ner-roui          #+#    #+#             */
/*   Updated: 2023/12/02 17:29:59 by ner-roui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (!(char)(c))
		return ((char *)str);
	return (0);
}

int	ft_printf_arg(const char *fmt, int i, va_list args)
{
    if (fmt[i + 1] == '%')
        return (ft_putchar(fmt[i + 1]));
    else if (fmt[i + 1] == 'c')
        return (ft_putchar(va_arg(args, int)));
    else if (fmt[i + 1] == 's')
        return (ft_putstr(va_arg(args, char *)));
    else if (fmt[i + 1] == 'd' || fmt[i + 1] == 'i')
        return (ft_printf_int(va_arg(args, int)));
    else if (fmt[i + 1] == 'u')
        return (ft_printf_unsigned(va_arg(args, unsigned int)));
    else if (fmt[i + 1] == 'x' || fmt[i + 1] == 'X')
    {
        if (fmt[i + 1] == 'X')
            return (ft_printf_H(va_arg(args, unsigned int)));
        else
            return (ft_printf_hex(va_arg(args, unsigned int)));
    }
    else if (fmt[i + 1] == 'p')
        return (ft_putstr("0x") + ft_printf_pointer(va_arg(args, long long)));
    else
        return (0);
}

int	ft_printf(const char *format, ...)
{
    va_list	args;
    va_start (args,format);
    
    int		i = 0;
    int		ret = 0;

    while (format[i])
    {
        if (format[i] == '%' && ft_strchr("cspdiuxX%", format[i + 1]))
        {
            ret += ft_printf_arg(format, i, args);
            i++;
        }
        else
            ret += ft_putchar(format[i]);
        i++;
    }
    va_end(args);
    return (ret);
}
// int main() {
//     char *s = "kjhh";
//     ft_printf("%s ",s);
// }



