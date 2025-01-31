/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narrospi <narrospi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 10:24:30 by narrospi          #+#    #+#             */
/*   Updated: 2024/10/01 11:08:09 by narrospi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_unsigned_nbr(unsigned int num)
{
	char	digit;

	if (num > 9)
	{
		print_unsigned(num / 10);
	}
	digit = num % 10 + '0';
	write(1, &digit, 1);
}

int	print_unsigned(unsigned int num)
{
	unsigned int	count;

	count = 0;
	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	print_unsigned_nbr(num);
	while (num)
	{
		num /= 10;
		count++;
	}
	return (count);
}
