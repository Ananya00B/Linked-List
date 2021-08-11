#include<stdio.h>
#include<stdlib.h>

void insertAtTheEnd();
void display();

struct node
{
    int data;
    struct node *next;
};
struct node *head, *temp;

int main()
{
    int opt = 1;
    head = 0;
    temp = (struct node*) malloc(sizeof(struct node));
    do{
        insertAtTheEnd();
        printf("\nDo you want to insert an element at the end?\n");
        printf("Choose : 1 -> YES, any other no. -> NO : ");
        scanf("%d", &opt);
    }while(opt == 1);

    display();
    return 0;
}

void insertAtTheEnd()
{
    struct node *newNode;
    newNode = (struct node*) malloc(sizeof(struct node));
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

            head = newNode;
            temp = head;
        }
        else
        {
            printf("Enter the element to insert : ");
            scanf("%d", &newNode->data);
            newNode->next = NULL;

            while (temp->next != 0)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
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