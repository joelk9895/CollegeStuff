#include <stdio.h>
#define MAX_SIZE 5

int queue[MAX_SIZE];
static int front, rear;

int isFull()
{
    if (rear == MAX_SIZE)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty()
{
    if (front == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
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
    queue[rear++] = num;
    return 1;
}

int deQueue()
{
    if (isEmpty())
    {
        printf("\nQueue is Empty");
        return 0;
    }
    if (front == rear)
    {
        front = -1;
        rear = 0;
        return 1;
    }
    int item = queue[front];
    front++;
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
    printf("%d", queue[front]);
    return 1;
}
void display()
{
    for (int i = front; i < rear; i++)
    {
        printf("\n %d", queue[i]);
    }
}
int main()
{
    printf("Welcome to Queue Operations!!!\nEnter the choice to continue\n1)Enqueue\n2)deQueue\n3)peek\n4)display\n5)exit\n");
    int choice, num;
    while (1)
    {
        printf("\nEnter the choice: ");
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
            printf("\nThank You");
            return 0;
        default:
            printf("\nInvalid Choice");
        }
    }
}