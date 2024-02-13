#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *create(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main()
{
    struct node *head = NULL;
    struct node *current = NULL;
    struct node *track = NULL;
    head = create(0);
    current = head;
    for (int i = 1; i < 10; i++)
    {
        struct node *newElem = create(i);
        current->next = newElem;
        current = newElem;
    }

    track = head;
    printf("Original Linked List: ");
    while (track)
    {
        printf("%d ", track->data);
        track = track->next;
    }
    printf("\n");

    current = head;
    int k = 0;
    struct node *prev = NULL;
    while (current != NULL && current->next != NULL)
    {

        struct node *first = current;
        struct node *second = current->next;
        first->next = second->next;
        second->next = first;
        if (prev == NULL)
        {
            head = second;
        }
        else
        {
            prev->next = second;
        }
        prev = first;
        current = first->next;
    }

    track = head;
    printf("Modified Linked List: ");
    while (track)
    {
        printf("%d ", track->data);
        track = track->next;
    }
    printf("\n");

    current = head;
    while (current != NULL)
    {
        struct node *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
