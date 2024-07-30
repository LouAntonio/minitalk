#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

static int state = 0;

void	bonus(int bit)
{
	bit = 0;
	write(1, "OK\n", 3);
}

void	keep_working(int bit)
{
	bit = 0;
	state = 1;
}

void	send_signal(int pid, unsigned char c){
	int i;

	i = 8;
	while (i--)
	{
		if (((c >> i) & 1))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (state == 0);
		state = 0;
	}

}

int	main(int ac, char **av){
	signal(SIGUSR1, &keep_working);
	signal(SIGUSR2, &bonus);
	int pid = atoi(av[2]);
	int i = 0;
	char *str = av[1];
	while (str[i]){
		send_signal(pid, str[i++]);
	}
	send_signal(pid, '\0');
}
