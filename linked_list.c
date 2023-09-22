#include "monty.h"

/**
 * first_node - Creates and populates a node.
 * @n: Number to go inside the node.
 * Return: Upon sucess a pointer to the node. Otherwise NULL.
 */
stack_t *first_node(int n)
{
	stack_t *element;

	element = malloc(sizeof(stack_t));
	if (element == NULL)
		malloc_err();

	element->n = n;
	element->prev = NULL;
	element->next = NULL;

	return (element);
}

/**
 * free_list - Frees nodes in the stack.
 * @first: head
 */

void free_list(stack_t *first)
{
	stack_t *ptr_tmp;

	if (first)
	{
		while (first)
		{
			ptr_tmp = first;
			first = first->next;
			free(ptr_tmp);
		}
	}
}
