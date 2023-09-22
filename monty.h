#ifndef MONTY_H
#define MONTY_H

/*Added To Enable GETLINE on a different POSIX system.*/
#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stddef.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern FILE *f_d;
extern char *buffer;
extern stack_t *first;
/*Type for opcode functions*/
typedef void (*op_func)(stack_t **, unsigned int);

/*Error hanlding*/
int opening_err(char *filename);
int push_int_err(unsigned int line_number);
int malloc_err(void);
int op_err(char *opcode, unsigned int line_number);

/*File ops*/
int read_file(FILE *fd);
int func(char *, char *, int, int);

stack_t *first_node(int n);
void free_list(stack_t *first);

void push_f(stack_t **, unsigned int);
void pop_f(stack_t **, unsigned int);
void pint_f(stack_t **, unsigned int);
void pall_f(stack_t **, unsigned int);
void queue(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void swap_f(stack_t **, unsigned int);
void add_f(stack_t **, unsigned int);
void sub_f(stack_t **, unsigned int);
void div_f(stack_t **, unsigned int);
void mul_f(stack_t **, unsigned int);
void mod_f(stack_t **, unsigned int);
void pchar_f(stack_t **, unsigned int);
void pstr_f(stack_t **, unsigned int);
void rotl_f(stack_t **, unsigned int);
void rotr_f(stack_t **, unsigned int);

#endif
