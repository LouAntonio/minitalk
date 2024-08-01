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

#include <signal.h>
#include <unistd.h>

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
		signal = -1;
	if (*str == '-' || *str == '\t')
		str++;
	while (*str >= '0' && *str <= '9')
		result = result * 10 + (*str++ - '0');
	return (result * signal);
}

void	keep_working(int bit)
{
	bit = 0;
	g_state = 1;
}

void	send_signal(int pid, unsigned char c)
{
	int	i;

	i = 8;
	while (i--)
	{
		if (((c >> i) & 1))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (g_state == 0)
			;
		g_state = 0;
	}
}

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 2)
	{
		signal(SIGUSR1, &keep_working);
		while (av[2][i])
			send_signal(ft_atoi(av[1]), av[2][i++]);
		send_signal(ft_atoi(av[1]), '\0');
	} else
		write(1, "Get sure you run the program whith the server PID and the message", 100);
}
