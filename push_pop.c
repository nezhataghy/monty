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
	if (new_node == NULL || *new_node == NULL)
	{
		free(buffer);
		buffer = NULL;
		fclose(f_d);
		exit(EXIT_FAILURE);
	}
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;
}

/**
 * pop_f -  removes the top element of the stack.
 * @new_node: double pointer to the node
 * @l_num: line number of of the opcode.
 */
void pop_f(stack_t **new_node, unsigned int l_num)
{
	stack_t *ptr_ptr;

	if (new_node == NULL || *new_node == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", l_num);
		free(buffer);
		buffer = NULL;
		fclose(f_d);
		exit(EXIT_FAILURE);
	}

	ptr_ptr = *new_node;
	*new_node = ptr_ptr->next;
	if (*new_node != NULL)
		(*new_node)->prev = NULL;
	free(ptr_ptr);
}
