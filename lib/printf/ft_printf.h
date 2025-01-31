/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narrospi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:25:54 by narrospi          #+#    #+#             */
/*   Updated: 2024/09/30 10:25:55 by narrospi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int		printchar(int c);
int		print_decimal(int num);
void	print_nbr(int num);
int		print_str(char *str);
int		print_unsigned(unsigned int num);
int		handle_hex(unsigned int num, int up_low);
int		print_pointer(unsigned long ptr);
void	print_hex(unsigned int num, char *base);
int		handle_format(va_list args, const char character);
int		ft_printf(char const *str, ...);

#endif
