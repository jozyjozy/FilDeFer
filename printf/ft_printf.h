/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlarue <jlarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:39:55 by jlarue            #+#    #+#             */
/*   Updated: 2022/12/16 11:03:10 by jlarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <assert.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"

int		ft_printf(const char *str, ...);
int		ft_checkinput(char c);
int		ft_convert(va_list arguments, char c);
int		ft_putchar_count(char c);
int		ft_putnbr_count(int n);
int		ft_count_nb(int n);
int		ft_putstr_count(char *str);
int		ft_count_unsnbr(unsigned int n);
int		ft_putunsnbr_count(unsigned int n);
int		ft_putnbhex_capital(unsigned long n);
int		ft_putnbhex_small(unsigned long n);
int		ft_putadress_hex_count(void	*str);
char	*ft_putbase_hex_adress(unsigned long str);
int		ft_count_addresshex(unsigned long n);

#endif
