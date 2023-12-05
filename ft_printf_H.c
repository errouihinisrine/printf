/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_H.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ner-roui <ner-roui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:12:10 by ner-roui          #+#    #+#             */
/*   Updated: 2023/12/02 14:47:17 by ner-roui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static	int ft_hex_len(unsigned	int num)
{
	int	len;

	if (num == 0)
		return 1;
	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

static void	ft_put_hex(unsigned int num)
{
	if (num >= 16)
	{
		ft_put_hex(num / 16);
		ft_put_hex(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar((num + '0'));
		else
		{
			ft_putchar((num - 10) + 'A');
		}
	}
}

int	ft_printf_H(unsigned int num)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_put_hex(num);
	return (ft_hex_len(num));
}
// int main()
// {
//     ft_printf_H(255);
//     return 0;
// }

