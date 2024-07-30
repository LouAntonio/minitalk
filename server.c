#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void  stoc(int bit)
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
		i = 0;
		c = 0;
	}
}

int main() 
{
pid_t pid = getpid();
printf("Server PID = %d\n", pid);

signal(SIGUSR1, stoc);
signal(SIGUSR2, stoc);
pause();
while (1);

return 0;
}