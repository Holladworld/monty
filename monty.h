#ifndef MONTY_H
#define MONTY_H
#define DIVIDERS " \n\t\r"
#define _POSIX_C_SOURCE 200809L
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>


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
extern stack_t **global_var;

int is_digit(char *agv, unsigned int count);
stack_t *add_node(stack_t **, const int);
void pall(stack_t **, unsigned int);
void push(stack_t **, unsigned int);
void pint(stack_t **, unsigned int);
void pop(stack_t **, unsigned int);
void swap(stack_t **, unsigned int);
void add(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void monty_opcode(char *, stack_t **, unsigned int);
void free_stack(void);
void sub(stack_t **, unsigned int);
void mul(stack_t **, unsigned int);
void divid(stack_t **, unsigned int);
void mod(stack_t **, unsigned int);
void pchar(stack_t **, unsigned int);
void pstr(stack_t **, unsigned int);
void rot1(stack_t **, unsigned int);
void rotr(stack_t **, unsigned int);
void reverse(stack_t *);
size_t print(stack_t *);


#endif
