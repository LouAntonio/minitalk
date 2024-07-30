#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void	send_signal(int pid, unsigned char c){
	int i = 8;
	int 	bit;
	int res = 0;

	while (i--)
	{
		if (((c >> i) & 1))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(350);
	}

}

int	main(int ac, char **av){
	int pid = atoi(av[2]);
	int i = 0;
	char *str = av[1];
	while (str[i]){
		send_signal(pid, str[i++]);
	}
}