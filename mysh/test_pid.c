#include <stdio.h>
#include <unistd.h>

/**
 * main - get the pid and ppid in the same process
 *
 * Return: pid and ppid values
 */
int main (void)
{
	/* declare variables to hold pid and ppid values */
	pid_t pid = getpid();
	pid_t ppid = getppid();

	/* print out pid and ppid */
	printf("pid = %d\n", pid);
	printf("ppid = %d\n", ppid);

	return (0);
}
