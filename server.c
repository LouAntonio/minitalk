/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lantonio <lantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 09:33:48 by lantonio          #+#    #+#             */
/*   Updated: 2024/07/31 09:40:55 by lantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	stoc(int bit, siginfo_t *info, void *context)
{
	static int	i = 0;
	static int	c = 0;

	c = c * 2;
	(void)context;
	if (bit == SIGUSR1)
		c = c + 1;
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		if (c == '\0')
			write(1, "\n", 1);
		i = 0;
		c = 0;
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
	{
		ft_printf("408 Request Timeout\n");
		c = 0;
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	s_c;

	s_c.sa_sigaction = stoc;
	s_c.sa_flags = SA_SIGINFO;
	sigemptyset(&s_c.sa_mask);
	sigaction(SIGUSR1, &s_c, NULL);
	sigaction(SIGUSR2, &s_c, NULL);
	ft_printf("Server PID = %d\n", getpid());
	while (1)
		pause();
	return (0);
}
