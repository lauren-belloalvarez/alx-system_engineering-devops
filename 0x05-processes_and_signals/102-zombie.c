#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * create_zombies - function creating zombies
 *
 * @num_zombies: number of zombie processes to create
 *
 * Return: 0 if processes are created and -1 on error
 */

int create_zombies(int num_zombies)
{
	pid_t pid;

	for (int i = 0; i < num_zombies; i++)
	{
		pid = fork();
		if (pid < 0)
		{
			perror("fork");
			return (-1);
		}
		else if (pid == 0)
		{
			exit(0);
		}
		else
		{
			printf("Zombie process created, PID: %d\n", pid);
		}
	}
	return (0);
}

/**
 * infinite_while - function creating an infinite loop
 *
 * Return: 0 if successful
 */

int infinite_while(void)
{
	while (1)
	{
		sleep(1);
	}
	return (0);
}

/**
 * main - entry point
 *
 * Return: 0 if succesful
 */

int main(void)
{
	if (create_zombies(5) < 0)
	{
		fprintf(stderr, "Failed to create zombie processes\n");
		return (1);
	}
	infinite_while();
	return (0);
}

