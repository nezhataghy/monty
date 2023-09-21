#include "monty.h"

/**
 * add_f - Adds the top two elements of the stack.
 * @new_node: double pointer to the node
 * @l_num: line number of of the opcode.
 */
void add_f(stack_t **new_node, unsigned int l_num)
{
	int somme;

	if (new_node == NULL || *new_node == NULL || (*new_node)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", l_num);
		free(buffer);
		buffer = NULL;
		fclose(f_d);
		exit(EXIT_FAILURE);
	}
	(*new_node) = (*new_node)->next;
	somme = (*new_node)->n + (*new_node)->prev->n;
	(*new_node)->n = somme;
	free((*new_node)->prev);
	(*new_node)->prev = NULL;
}

/**
 * sub_f - Adds the top two elements of the stack.
 * @new_node: double pointer to the node
 * @l_num: line number of of the opcode.
 */
void sub_f(stack_t **new_node, unsigned int l_num)
{
	int somme;

	if (new_node == NULL || *new_node == NULL || (*new_node)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", l_num);
		free(buffer);
		buffer = NULL;
		fclose(f_d);
		exit(EXIT_FAILURE);
	}
	(*new_node) = (*new_node)->next;
	somme = (*new_node)->n - (*new_node)->prev->n;
	(*new_node)->n = somme;
	free((*new_node)->prev);
	(*new_node)->prev = NULL;
}
