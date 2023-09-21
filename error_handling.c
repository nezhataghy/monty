#include "monty.h"

/**
 * opening_err - Prints file opening error message.
 * @file_name: Name of file failed to open
 * Return: EXIT_FAILURE.
 */
int opening_err(char *file_name)
{
	fprintf(stderr, "Error: Can't open file %s\n", file_name);
	return (EXIT_FAILURE);
}

/**
 * op_err - Prints error message.
 * @opcode: Opcode where error occurred.
 * @l_num: Line where error occured.
 * Return: EXIT_FAILURE.
 */
int op_err(char *opcode, unsigned int l_num)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
			l_num, opcode);
	return (EXIT_FAILURE);
}
/**
 * malloc_err - Prints malloc error message.
 * Return: EXIT_FAILURE.
 */

int malloc_err(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

/**
 * push_int_err - Prints error message.
 * @l_num: Line where error occurred.
 * Return: EXIT_FAILURE.
 */
int push_int_err(unsigned int l_num)
{
	fprintf(stderr, "L%u: usage: push integer\n", l_num);
	return (EXIT_FAILURE);
}
