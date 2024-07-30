#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void  stoc(int bit, siginfo_t *info, void *context)
{
	static int i = 0;
	static int c = 0;

	c = c * 2;
	if (bit == SIGUSR1)
		c = c + 1;
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		if (c == '\0'){
			write(1, "\n", 1);
			kill(info->si_pid, SIGUSR2);
		}
		i = 0;
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);

}

int main(void) {
	struct sigaction c;

	c.sa_sigaction = stoc;
	c.sa_flags = SA_SIGINFO;
	sigemptyset(&c.sa_mask);
	sigaction(SIGUSR1, &c, NULL);
	sigaction(SIGUSR2, &c, NULL);
	printf("Server PID = %d\n", getpid());

	while (1)
		pause();

	return 0;
}
