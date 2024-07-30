#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	send_signal(unsigned char c){
	int i = 8;
	int 	bit;
	int res = 0;

	while (i--)
	{
		if (((c >> i) & 1))
			res = res * 2 + 1;
		else
			res = res * 2;
		bit = ((c >> i) & 1) + '0';
		write(1, &bit, 1);
	}
	write(1, &res, 1);
	write(1, "\n", 1);
}

int	main(int ac, char **av){
	int i = 0;
	char *str = av[1];
	while (str[i])
		send_signal(str[i++]);
}