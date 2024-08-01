/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lantonio <lantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 08:24:55 by lantonio          #+#    #+#             */
/*   Updated: 2024/05/28 08:01:46 by lantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexlen(unsigned	int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_printfhex(unsigned int num, const char nbrformat)
{
	if (num >= 16)
	{
		ft_printfhex(num / 16, nbrformat);
		ft_printfhex(num % 16, nbrformat);
	}
	else
	{
		if (num <= 9)
			ft_putchar((num + '0'));
		else
		{
			if (nbrformat == 'x')
				ft_putchar((num - 10 + 'a'));
			if (nbrformat == 'X')
				ft_putchar((num - 10 + 'A'));
		}
	}
}

int	ft_puthex(unsigned int nbr, const char nbrformat)
{
	if (nbr == 0)
		return (ft_putchar('0'));
	else
		ft_printfhex(nbr, nbrformat);
	return (ft_hexlen(nbr));
}
