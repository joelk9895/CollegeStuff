#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *createTrack = NULL;

void insert(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
        createTrack = newNode;
    }
    else
    {
        createTrack->next = newNode;
        createTrack = newNode;
    }
}

struct Node *findMin()
{
    struct Node *min = head;
    struct Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data < min->data)
        {
            min = temp;
        }
        temp = temp->next;
    }
    return min;
}

void deleteMin(struct Node *min)
{
    struct Node *temp = head;
    struct Node *prev = NULL;
    while (temp != min)
    {
        prev = temp;
        temp = temp->next;
    }
    if (prev == NULL)
    {
        head = head->next;
    }
    else
    {
        prev->next = temp->next;
    }
    free(min);
}

void printList()
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    char choice;
    int data;
    while (1)
    {
        printf("\n---- Singly Linked List Operations ----\n");
        printf("1. Insert\n");
        printf("2. Delete Minimum\n");
        printf("3. Print List\n");
        printf("4. Display Minimum\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice)
        {
        case '1':
            printf("Enter data to insert (press 'q' to quit): ");
            while (scanf("%d", &data) == 1)
            {
                insert(data);
                printf("Data inserted successfully. Enter next data (press 'q' to quit): ");
            }
            break;
        case '2':
            if (head == NULL)
            {
                printf("List is empty. Cannot delete minimum.\n");
            }
            else
            {
                struct Node *min = findMin();
                deleteMin(min);
                printf("Minimum element deleted successfully.\n");
            }
            break;
        case '3':
            if (head == NULL)
            {
                printf("List is empty.\n");
            }
            else
            {
                printf("Current List: ");
                printList();
            }
            break;
        case '4':
            if (head == NULL)
            {
                printf("List is empty. There is no minimum element.\n");
            }
            else
            {
                struct Node *min = findMin();
                printf("Minimum element in the list: %d\n", min->data);
            }
            break;
        case '5':
            printf("Exiting program.\n");
            exit(0);
        default:
            printf("Invalid choice! Please enter a valid choice.\n");
        }
    }

    return 0;
}