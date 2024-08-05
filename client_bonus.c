/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lantonio <lantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 09:33:55 by lantonio          #+#    #+#             */
/*   Updated: 2024/07/31 09:39:33 by lantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_state = 0;

int	ft_atoi(char *str)
{
	int	result;
	int	signal;

	result = 0;
	signal = 1;
	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == '-')
		exit(1);
	if (*str == '-' || *str == '\t')
		str++;
	while (*str >= '0' && *str <= '9')
		result = result * 10 + (*str++ - '0');
	return (result * signal);
}

void	bonus(int bit)
{
	(void)bit;
	write(1, "OK\n", 3);
}

void	keep_working(int bit)
{
	(void)bit;
	g_state = 1;
}

void	send_signal(int pid, unsigned char c)
{
	int	i;

	i = 8;
	while (i--)
	{
		if (((c >> i) & 1))
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(1);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(1);
		}
		while (g_state == 0)
			;
		g_state = 0;
	}
}

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 3)
	{
		if (ft_atoi(av[1]))
		{
			signal(SIGUSR2, &bonus);
			signal(SIGUSR1, &keep_working);
			while (av[2][i])
				send_signal(ft_atoi(av[1]), av[2][i++]);
			send_signal(ft_atoi(av[1]), '\0');
		}
		else
			ft_printf("Check the PID\n");
	}
	else
		ft_printf("[./client][PID][message]\n");
}
