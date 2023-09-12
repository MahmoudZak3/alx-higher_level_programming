#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_listint - listint_t list to be printed
 * @h:  head of list pointer
 * Return: nodes
 */
size_t print_listint(const listint_t *h)
{
    const listint_t *current;
    unsigned int n;

    current = h;
    n = 0;
    while (current != NULL)
    {
        printf("%i\n", current->n);
        current = current->next;
        n++;
    }

    return (n);
}

/**
 * add_nodeint_end -  new node to add to the end of a listint_t
 * @head: pointer  first node of listint_t pointer
 * @n: include integer in new node
 * Return: the new element address  or NULL
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
    listint_t *new;
    listint_t *current;

    current = *head;

    new = malloc(sizeof(listint_t));
    if (new == NULL)
        return (NULL);

    new->n = n;
    new->next = NULL;

    if (*head == NULL)
        *head = new;
    else
    {
        while (current->next != NULL)
            current = current->next;
        current->next = new;
    }

    return (new);
}

/**
 * free_listint - free  listint_t
 * @head: pointer  list to  free
 * Return: 0
 */
void free_listint(listint_t *head)
{
    listint_t *current;

    while (head != NULL)
    {
        current = head;
        head = head->next;
        free(current);
    }
}
