#include "monty.h"

/**
 * mul_f - multiplies the second top element
 * of the stack with the top element
 * @new_node: double pointer to the node
 * @l_num: line number of of the opcode.
 */
void mul_f(stack_t **new_node, unsigned int l_num)

{

	if (!(new_node) || !(*new_node) || !((*new_node)->next))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", l_num);
		free(buffer);
		buffer = NULL;
		fclose(f_d);
		exit(EXIT_FAILURE);
	}
	(*new_node)->next->n *= (*new_node)->n;
	*new_node = (*new_node)->next;
	free((*new_node)->prev);
	(*new_node)->prev = NULL;
}

/**
 * mod_f - computes the rest of the division
 * of the second top element of the stack by the top element
 * @new_node: double pointer to the node
 * @l_num: line number of of the opcode.
 */
void mod_f(stack_t **new_node, unsigned int l_num)
{
	if (!(new_node) || !(*new_node) || !((*new_node)->next))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", l_num);
		free(buffer);
		buffer = NULL;
		fclose(f_d);
		exit(EXIT_FAILURE);
	}
	if ((*new_node)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", l_num);
		free(buffer);
		buffer = NULL;
		fclose(f_d);
		exit(EXIT_FAILURE);
	}
	(*new_node)->next->n %= (*new_node)->n;
	*new_node = (*new_node)->next;
	free((*new_node)->prev);
	(*new_node)->prev = NULL;
}
