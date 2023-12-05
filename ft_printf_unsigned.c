/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ner-roui <ner-roui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:33:03 by ner-roui          #+#    #+#             */
/*   Updated: 2023/12/02 13:41:36 by ner-roui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static  char *ft_utoa(unsigned int nbr)
{
    int numDigits = 1;
    unsigned int temp = nbr;
    while (temp >= 10) {
        temp /= 10;
        numDigits++;
    }
    char *str = (char *)malloc((numDigits + 1) * sizeof(char));

    if (str == NULL) {
        return NULL;
    }
    
    int i = numDigits;
    while ( i--) {
        str[i] = '0' + (nbr % 10);
        nbr /= 10;
    }
    str[numDigits] = '\0';

    return str;
}

int	ft_printf_unsigned(unsigned int nbr)
{
    char	*str;
    int		len;

    str = ft_utoa(nbr);
    len = ft_putstr(str);
    free(str);
    return (len);
}


// int main()
// {
//     unsigned int num = 12345;
//     int len = ft_printf_unsigned(num);

//     printf("\nLength of the string: %d\n", len);

//     return 0;
// }


