#include "monty.h"

/**
 * push_f - pushes an element to the stack
 * @new_node: Pointer to the new node.
 * @l_num: line number of of the opcode.
 */
void push_f(stack_t **new_node, unsigned int l_num)
{
	stack_t *tmp;

	(void)l_num;
	if (!(new_node) || !(*new_node))
	{
		free(buffer);
		buffer = NULL;
		free_list();
		fclose(f_d);
		exit(EXIT_FAILURE);
	}
	if (first == NULL)
	{
		first = *new_node;
		return;
	}
	tmp = first;
	first = *new_node;
	first->next = tmp;
	tmp->prev = first;
}

/**
 * pop_f -  removes the top element of the stack.
 * @new_node: double pointer to the node
 * @l_num: line number of of the opcode.
 */
void pop_f(stack_t **new_node, unsigned int l_num)
{
	stack_t *ptr_ptr;

	if (!(new_node) || !(*new_node))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", l_num);
		free(buffer);
		buffer = NULL;
		free_list();
		fclose(f_d);
		exit(EXIT_FAILURE);
	}

	ptr_ptr = *new_node;
	*new_node = ptr_ptr->next;
	if (*new_node != NULL)
		(*new_node)->prev = NULL;
	free(ptr_ptr);
}
