/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ner-roui <ner-roui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:25:37 by ner-roui          #+#    #+#             */
/*   Updated: 2023/12/02 15:39:26 by ner-roui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_hex_len(unsigned	int num)
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

void	ft_put_hex(unsigned int num)
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
			ft_putchar((num - 10 + 'a'));
		}
	}
}

int	ft_printf_hex(unsigned int num)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_put_hex(num);
	return (ft_hex_len(num));
}
// int main()
// {
//     ft_printf_hex(255);
//     return 0;
// }
