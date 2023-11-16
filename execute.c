#include "monty.h"
/**
* execute - executes the opcode
* @stack: head linked list - stack
* @counter: line_counter
* @file: poiner to monty file
* @content: line content
* Return: no return
*/
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", cus_push},
				{"pall", cus_pall},
				{"pint", cus_pint},
				{"pop", cus_pop},
				{"swap", cus_swap},
				{"add", cus_add},
				{"nop", cus_nop},
				{"sub", cus_sub},
				{"div", cus_div},
				{"mul", cus_mul},
				{"mod", cus_mod},
				{"pchar", cus_pchar},
				{"pstr", cus_pstr},
				{"rotl", cus_rotl},
				{"rotr", cus_rotr},
				{"queue", cus_queue},
				{"stack", cus_stack},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{
			opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
