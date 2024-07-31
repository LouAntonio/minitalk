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

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

static int	g_state = 0;

void	bonus(int bit)
{
	bit = 0;
	write(1, "OK\n", 3);
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

	signal(SIGUSR1, &keep_working);
	signal(SIGUSR2, &bonus);
	while (av[1][i])
		send_signal(atoi(av[2]), av[1][i++]);
	send_signal(atoi(av[2]), '\0');
}
