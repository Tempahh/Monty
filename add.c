#include "monty.h"
/**
 * cus_add - adds the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void cus_add(stack_t **head, unsigned int counter)
{
	stack_t *a;
	int len = 0, aux;

	a = *head;
	while (a)
	{
		a = a->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too saort\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*aead);
		exit(EXIT_FAILURE);
	}
	a = *head;
	aux = a->n + a->next->n;
	a->next->n = aux;
	*head = a->next;
	free(a);
}
