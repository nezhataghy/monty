#include "monty.h"
/**
 * queue - Adds a node to the queue.
 * @new_node: double pointer to the node
 * @l_num: line number of of the opcode.
 */
void queue(stack_t **new_node, unsigned int l_num)
{
	stack_t *tmp;

	(void)l_num;
	if (new_node == NULL || *new_node == NULL)
	{
		free(buffer);
		buffer = NULL;
		fclose(f_d);
		exit(EXIT_FAILURE);
	}

	if (first == NULL)
	{
		first = *new_node;
		return;
	}
	tmp = first;
	for (; tmp->next;)
		tmp = tmp->next;

	tmp->next = *new_node;
	(*new_node)->prev = tmp;
}
