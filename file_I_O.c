#include "monty.h"

int read_file(FILE *fd);

char *buffer = NULL;
/**
 * read_file - Reads the content of a file
 * @fd: file descriptor
 * Return: exit statuts
 */

int read_file(FILE *fd)
{
	int l_num = 1, type = 0, exit_stat = EXIT_SUCCESS;
	size_t n = 0;
	char *opcode, *value;
	const char *seperator = "\n ";

	while (getline(&buffer, &n, fd) != EOF)
	{
		if (buffer == NULL)
			return (malloc_err());

		opcode = strtok(buffer, seperator);

		if (opcode == NULL)
		{
			l_num++;
			continue;
		}

		value = strtok(NULL, seperator);

		if (strcmp(opcode, "queue") == 0)
			type = 1;
		else if (strcmp(opcode, "stack") == 0)
			type = 0;

		exit_stat = func(opcode, value, l_num, type);
		l_num++;
	}
	free(buffer);
	return (exit_stat);
}

/**
 * func - Finds the function
 * @opcode: The operation code
 * @value: value for the operation
 * @l_num: Line number
 * @type: format specifier
 * Return: exit status
 */

int func(char *opcode, char *value, int l_num, int type)
{
	stack_t *element;
	int signe = 1, flag = 1, i = 0, j = 0;

	instruction_t array_func[] = {
		{"push", push_f},
		{"pall", pall_f},
		{"pint", pint_f},
		{"pop", pop_f},
		{"nop", nop},
		{"swap", swap_f},
		{"add", add_f},
		{"sub", sub_f},
		{"div", div_f},
		{"mul", mul_f},
		{"mod", mod_f},
		{NULL, NULL}};

	if (opcode[0] == '#')
		return (0);

	while (array_func[i].opcode)
	{
		if (strcmp(opcode, array_func[i].opcode) == 0)
		{
			if (strcmp(opcode, "push") == 0)
			{
				if (value != NULL && (*value) == '-')
				{
					signe = -1;
					value++;
				}
				if (value == NULL)
					return (push_int_err(l_num));
				while (*(value + j) != '\0')
				{
					if (isdigit(*(value + j) == 0))
						return (push_int_err(l_num));
					j++;
				}
				element = first_node(signe * atoi(value));
				if (type == 1)
					queue(&element, l_num);
				else if (type == 0)
					array_func[i].f(&element, l_num);
			}
			else
				array_func[i].f(&first, l_num);

			flag = 0;
		}
		i++;
	}
	if (flag == 1)
		return (op_err(opcode, l_num));

	return (EXIT_SUCCESS);
}
