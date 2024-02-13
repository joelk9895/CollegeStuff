#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node *insertElement(struct node *root, int data)
{
    if (!root)
    {
        return createNode(data);
    }
    else if (data <= root->data)
    {
        root->left = insertElement(root->left, data);
    }
    else
    {
        root->right = insertElement(root->right, data);
    }
    return root;
}

void inorderTraversal(struct node *root)
{
    if (root)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(struct node *root)
{
    if (root)
    {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(struct node *root)
{
    if (root)
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}
void deleteNode(struct node *root, int data){
    if(root == NULL){
        return;
    }
    
}

int main()
{
    struct node *root = NULL;
    root = insertElement(root, 50);
    root = insertElement(root, 30);
    root = insertElement(root, 20);
    root = insertElement(root, 40);
    root = insertElement(root, 70);
    root = insertElement(root, 60);
    root = insertElement(root, 80);

    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder Traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}