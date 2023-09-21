#include "monty.h"

/**
 * nop - Does nothing.
 * @new_node: double pointer to the node
 * @l_num: line number of of the opcode.
 */
void nop(stack_t **new_node, unsigned int l_num)
{
	(void)new_node;
	(void)l_num;
}

/**
 * swap_f - Swaps the top two elements of the stack.
 * @new_node: double pointer to the node
 * @l_num: line number of of the opcode.
 */
void swap_f(stack_t **new_node, unsigned int l_num)
{
	stack_t *ptr_tmp;

	if (new_node == NULL || *new_node == NULL || (*new_node)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", l_num);
		free(buffer);
		buffer = NULL;
		fclose(f_d);
		exit(EXIT_FAILURE);
	}

	ptr_tmp = (*new_node)->next;
	(*new_node)->next = ptr_tmp->next;
	if (ptr_tmp->next)
		ptr_tmp->next->prev = *new_node;
	ptr_tmp->next = *new_node;
	(*new_node)->prev = ptr_tmp;
	ptr_tmp->prev = NULL;
	*new_node = ptr_tmp;
}
