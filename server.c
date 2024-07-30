#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() 
{
  pid_t pid = getpid();
  printf("Server PID = %d\n", pid);
  
  signal(SIGINT, signal_handler);
  signal(SIGTERM, signal_handler);

  return 0;
}