#include<stdio.h>
#include<stdlib.h>

void insertAtTheEnd();
void display();
void deleteAtTheEnd();

struct node
{
    int data;
    struct node *next;
};
struct node *head, *temp;

int n, i = 1;
int main()
{
    int opt = 1;
    head = 0;
    temp = (struct node*) malloc(sizeof(struct node));
    printf("Enter the number of elements you wanna insert in the linked list : ");
    scanf("%d", &n);

    while (i <= n)
    {
        insertAtTheEnd();
        i++;
    }
    display();

    printf("\nDeleting Last element in the linked list....\n");
    do{
        deleteAtTheEnd();
        printf("\nDo you want to delete another last element in the linked list?\n");
        printf("Choose : 1 -> YES, any other no. -> NO : ");
        scanf("%d", &opt);
    }while(opt == 1);

    return 0;
}

void deleteAtTheEnd()
{
    if(head != 0)
    {
        struct node *prevNode;
        temp = head;
        while (temp->next != 0)
        {
            prevNode = temp;
            temp = temp->next;
        }
        
        if(temp == head)
        {
            head = 0;
        }
        else
        {
            prevNode->next = 0;
        }

        free(temp);
        printf("Last element has been deleted.\n");
        display();
    }
    
    if(head == 0)
    {
        printf("\nNo element left in the linked list.");
        exit(1);
    }
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
            printf("Enter the next element to insert : ");
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
    temp = head;
    printf ("\nLinked List: ");
    while (temp != NULL)
    {
        printf ("%d", temp->data);
        temp = temp->next;
        if(temp)
            printf(" -> ");
    }
    printf("\n");
}