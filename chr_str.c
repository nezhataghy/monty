#include "monty.h"

/**
 * pchar_f - prints the char at the top
 * @new_node: double pointer to the node
 * @l_num: line number of of the opcode.
 */
void pchar_f(stack_t **new_node, unsigned int l_num)
{
    int code;

    if (new_node == NULL || *new_node == NULL)
    {
        fprintf(stderr, "L%d: can't pchar, stack empty\n", l_num);
        free(buffer);
        buffer = NULL;
        fclose(f_d);
        exit(EXIT_FAILURE);
    }

    code = (*new_node)->n;
    if (code < 0 || code > 127)
    {
        fprintf(stderr, "L%d: can't pchar, value out of range\n", l_num);
        free(buffer);
        buffer = NULL;
        fclose(f_d);
        exit(EXIT_FAILURE);
    }
    printf("%c\n", code);
}

/**
 * print_str - prints the string starting at the top
 * @new_node: double pointer to the node
 * @l_num: line number of of the opcode.
 */
void pstr_f(stack_t **new_node, unsigned int l_num)
{
    int code;
    stack_t *ptr_tmp;

    (void)l_num;
    if (new_node == NULL || *new_node == NULL)
    {
        printf("\n");
        return;
    }
    ptr_tmp = *new_node;
    for (; ptr_tmp;)
    {
        code = ptr_tmp->n;
        if (code <= 0 || code > 127)
            break;
        printf("%c", code);
        ptr_tmp = ptr_tmp->next;
    }
    printf("\n");
}
