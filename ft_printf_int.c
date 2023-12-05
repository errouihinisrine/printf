/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ner-roui <ner-roui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:30:47 by ner-roui          #+#    #+#             */
/*   Updated: 2023/12/02 12:51:40 by ner-roui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int ft_intlen(int nbr)
{
    int digits = 0;
    while(nbr != 0)
    {
        digits++;
        nbr /= 10;
    }
    return digits;
}
static char *ft_itoa(int nbr)
{
    int digits = ft_intlen(nbr);
    if(nbr < 0)
    {
        nbr *= -1;
        digits++;
    }
    char *str = malloc((digits + 1) * sizeof(char));
    str[digits] = '\0';
    while(digits-- > 0)
    {
        str[digits] = (nbr % 10) + '0';
        nbr /= 10;
    }
    if(nbr < 0)
    {
     str[digits] = ft_putchar('-');   
    }
    return str;
}
int	ft_printf_int(int nbr)
{
    char	*str;
    int		len;

    str = ft_itoa(nbr);
    len = ft_putstr(str);
    free(str);
    return (len);
}

