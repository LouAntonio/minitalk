/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lantonio <lantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 09:09:15 by lantonio          #+#    #+#             */
/*   Updated: 2024/05/28 08:07:04 by lantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	stridentifier(va_list args, const char str)
{
	if (str == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (str == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (str == 'p')
		return (ft_putptr(va_arg(args, unsigned long long)));
	else if (str == 'd' || str == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (str == 'u')
		return (ft_putunsigned(va_arg(args, unsigned int)));
	else if (str == 'x' || str == 'X')
		return (ft_puthex(va_arg(args, unsigned int), str));
	else if (str == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = -1;
	len = 0;
	va_start(args, str);
	while (str[++i])
	{
		if (str[i] == '%')
		{
			len += stridentifier(args, str[i + 1]);
			i++;
		}
		else
			len += ft_putchar(str[i]);
	}
	va_end(args);
	return (len);
}

/*int main()
{
	//char *p;
	//char *p = NULL;
	char p[] = "LouAntonio";

	int ret = ft_printf("Char %c\n", 'a');
	int ret2 = printf("Char %c\n", 'a');
	printf("%d\n%d\n---\n", ret, ret);

	ret = ft_printf("String %s\n", "LouAntonio");
	ret2 = printf("String %s\n", "LouAntonio");
	printf("%d\n%d\n---\n", ret, ret);

	ret = ft_printf("ptr %p\n", p);
	ret2 = printf("ptr %p\n", p);
	printf("%d\n%d\n---\n", ret, ret);

	ret = ft_printf("Decimal %d\n", 123);
	ret2 = printf("Decimal %d\n", 123);
	printf("%d\n%d\n---\n", ret, ret);

	ret = ft_printf("Inteiro %i\n", 123);
	ret2 = printf("Inteiro %i\n", 123);
	printf("%d\n%d\n---\n", ret, ret);

	ret = ft_printf("Sem sinal %u\n", -123);
	ret2 = printf("Sem sinal %u\n", -123);
	printf("%d\n%d\n---\n", ret, ret);

	ret = ft_printf("hex %x\n", -294967284);
	ret2 = printf("hex %x\n", -294967284);
	printf("%d\n%d\n---\n", ret, ret);

	ret = ft_printf("HEX %X\n", -294967284);
	ret2 = printf("HEX %X\n", -294967284);
	printf("%d\n%d\n---\n", ret, ret);

	ret = ft_printf("percentagem %%\n");
	ret2 = printf("percentagem %%\n");
	printf("%d\n%d\n---\n", ret, ret);
	return 0;
}
*/