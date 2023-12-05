/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ner-roui <ner-roui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:34:42 by ner-roui          #+#    #+#             */
/*   Updated: 2023/12/02 13:18:06 by ner-roui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
#include <stdlib.h>

int		ft_printf(const char *format, ...);
int		ft_printf_pointer(unsigned long long ptr);
int		ft_printf_unsigned(unsigned int nbr);
int		ft_putstr(char *s);
int		ft_printf_int(int nbr);
int		ft_putchar(char c);
int	    ft_printf_hex(unsigned int num);
int	    ft_printf_H(unsigned int num);

#endif
