#include "monty.h"

/**
 * rotl_f - rotates the stack to the top.
 * @new_node: double pointer to the node
 * @l_num: line number of of the opcode.
 */
void rotl_f(stack_t **new_node, unsigned int l_num)
{
	stack_t *ptr_tmp;

	(void)l_num;
	if (!(!(new_node) || !(*new_node) || !((*new_node)->next)))
	{
		ptr_tmp = *new_node;
		for (; ptr_tmp->next;)
			ptr_tmp = ptr_tmp->next;

		ptr_tmp->next = *new_node;

		(*new_node)->prev = ptr_tmp;
		*new_node = (*new_node)->next;

		(*new_node)->prev->next = NULL;
		(*new_node)->prev = NULL;
	}
}

/**
 * rotr_f - rotates the stack to the bottom.
 * @new_node: double pointer to the node
 * @l_num: line number of of the opcode.
 */
void rotr_f(stack_t **new_node, unsigned int l_num)
{
	stack_t *ptr_tmp;

	(void)l_num;
	if (!(!(new_node) || !(*new_node) || !((*new_node)->next)))
	{
		ptr_tmp = *new_node;

		for (; ptr_tmp->next;)
			ptr_tmp = ptr_tmp->next;

		ptr_tmp->next = *new_node;

		ptr_tmp->prev->next = NULL;
		ptr_tmp->prev = NULL;

		(*new_node)->prev = ptr_tmp;
		(*new_node) = ptr_tmp;
	}
}
