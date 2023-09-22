#include "monty.h"

stack_t *first = NULL;
FILE *f_d = NULL;

/**
 * main - Entry Point
 * @argc: Number of command line arguments.
 * @argv: An array containing the arguments.
 * Return: Always Zero.
 */
int main(int argc, char **argv)
{

	int exit_stat;

	if (!(argc == 2))
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	f_d = fopen(argv[1], "r");

	if (f_d == NULL)
		return (opening_err(argv[1]));

	exit_stat = read_file(f_d);
	fclose(f_d);
	free_list(first);
	return (exit_stat);
}
