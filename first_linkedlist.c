#include<stdio.h>
#include<stdlib.h>

void insertAtBeginning();
void display();

struct node
{
    int data;
    struct node *next;
};
struct node *head;

int main()
{
    int opt = 1;
    head = 0;
    do{
        insertAtBeginning();
        printf("\nDo you want to insert an element at the beginning?\n");
        printf("Choose : 1 -> YES, any other no. -> NO : ");
        scanf("%d", &opt);
    }while(opt == 1);

    display();
    return 0;
}

void insertAtBeginning()
{
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    if(newNode == 0)
    {
        printf("Memory not allocated\n");
    }
    else
    {
        if(head == 0)
        {
            printf("Enter the first element to insert : ");
            scanf("%d", &newNode->data);
            newNode->next = NULL;
        }
        else
        {
            printf("Enter the element to insert : ");
            scanf("%d", &newNode->data);
            newNode->next = head;
        }
        head = newNode;
    }
}

void display()
{
    printf ("\nLinked List: ");
    while (head != NULL)
    {
        printf ("%d", head->data);
        head = head->next;
        if(head)
            printf(" -> ");
    }
    printf("\n");
    
}