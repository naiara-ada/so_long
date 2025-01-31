/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_decimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narrospi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 10:42:32 by narrospi          #+#    #+#             */
/*   Updated: 2024/10/01 11:07:07 by narrospi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_nbr(int num)
{
	char	digit;

	if (num == -2147483648)
	{
		write (1, "-2147483648", 11);
		return ;
	}
	if (num < 0)
	{
		write (1, "-", 1);
		num *= -1;
	}
	if (num > 9)
	{
		print_nbr(num / 10);
	}
	digit = num % 10 + '0';
	write (1, &digit, 1);
}

int	print_decimal(int num)
{
	int	count;

	count = 0;
	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	print_nbr(num);
	if (num < 0)
	{
		count++;
		num *= -1;
	}
	while (num)
	{
		count++;
		num /= 10;
	}
	return (count);
}
