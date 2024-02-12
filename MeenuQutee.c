#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define Max_size 5
int Q[Max_size];
int front = -1, rear = -1, data, item;
bool is_full()
{
    if (front == ((rear + 1) % Max_size))
        return true;
    else
        return false;
}
bool is_empty()
{
    if (front == -1 && rear == -1)
        return true;
    else
        return false;
}
void Enqueue(int data)
{
    if (is_full())
    {
        printf("Queue full");
        return;
    }
    if (front == -1)
    {
        front = rear = 0;
        Q[rear] = data;
    }
    else if (((rear + 1) % Max_size) != front)
    {
        Q[rear] = data;
    }
}

void Dequeue()
{
    if (is_empty())
    {
        printf("Queue empty");
        return;
    }
    item = Q[front];
    printf("Deleted element : %d", item);
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = ((front + 1) % Max_size);
    }
}
void Display_queue()
{
    if (is_empty())
        printf("Queue empty");
    else
    {
        for (int i = front; i <= rear; i++)
            printf("%d", Q[i]);
    }
}
int main()
{
    int op, data;

    printf("1.Enqueue\n2.Dequeue\n3.Display_queue\n");
    while (true)
    {
        printf("Enter the Option (Press 0 to exit): ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("Enter data:");
            scanf("%d", &data);
            Enqueue(data);
            break;
        case 2:
            Dequeue();
            break;
        case 3:
            Display_queue();
            break;
        }
        if (op == 0)
            break;
    }
    return 0;
}