/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ner-roui <ner-roui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:24:41 by ner-roui          #+#    #+#             */
/*   Updated: 2023/12/02 12:19:59 by ner-roui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static size_t ft_strlen(char *s)
{
    size_t i = 0;
    while(s[i] != '\0')
    {
        i++;
    }
    return (i);
}
int ft_putstr(char *s)
{
    if (!s)
    {
        write(1,"(null)",6);
        return(6);
        
    }
    write(1, s,ft_strlen(s));
    return(ft_strlen(s));
}