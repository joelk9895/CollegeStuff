#include <stdio.h>
#define MAX_SIZE 3

int queue[MAX_SIZE];
static int front, rear;

int isFull()
{
    if ((front == rear + 1) || (front == 0 && rear == MAX_SIZE - 1))
        return 1;
    return 0;
}

int isEmpty()
{
    if (front == -1)
        return 1;
    return 0;
}

int enQueue(int num)
{
    if (isFull())
    {
        printf("\nQueue is Full");
        return 0;
    }
    if (front == -1)
        front++;
    rear = (rear + 1) % MAX_SIZE;
    queue[rear] = num;
    return 1;
}

int deQueue()
{
    if (isEmpty())
    {
        printf("\nQueue is Empty");
        return 0;
    }
    int item = queue[front];
    front = (front + 1) % MAX_SIZE;
    printf("%d has been removed", item);
    return 1;
}

int peek()
{
    if (isEmpty())
    {
        printf("\nQueue is Empty");
        return 0;
    }
    int item = queue[front];
    printf("%d is at the front of the queue", item);
    return 1;
}

int display()
{
    if (isEmpty())
    {
        printf("\nQueue is Empty");
        return 0;
    }
    printf("\nQueue: ");
    for (int i = front; i != rear; i = (i + 1) % MAX_SIZE)
    {
        printf("%d ", queue[i]);
    }
    return 1;
}

int main()
{
    int choice, num;
    front = -1;
    rear = -1;
    do
    {
        printf("\n\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Peek");
        printf("\n4. Display");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the number to be inserted: ");
            scanf("%d", &num);
            enQueue(num);
            break;
        case 2:
            deQueue();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("\nExiting...");
            break;
        default:
            printf("\nInvalid Choice");
        }
    } while (choice != 5);
    return 0;
}