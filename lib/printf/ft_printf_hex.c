/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narrospi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:28:49 by narrospi          #+#    #+#             */
/*   Updated: 2024/10/01 11:07:26 by narrospi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hex(unsigned int num, char *base)
{
	if (num >= 16)
		print_hex(num / 16, base);
	write(1, &base[num % 16], 1);
}

int	handle_hex(unsigned int num, int up_low)
{
	int		count;
	char	*base;

	count = 0;
	if (up_low == 0)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	print_hex(num, base);
	while (num)
	{
		count++;
		num /= 16;
	}
	return (count);
}
