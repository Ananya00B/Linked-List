#include<stdio.h>
#include<stdlib.h>

void insertAtTheEnd();
void display();
void deleteNthElement();

struct node
{
    int data;
    struct node *next;
};
struct node *head, *temp, *newNode;

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

    printf("\nDeleting nth element in the linked list....\n");
    do{
        deleteNthElement();
        printf("\nDo you want to delete an element in the linked list?\n");
        printf("Choose : 1 -> YES, any other no. -> NO : ");
        scanf("%d", &opt);
    }while(opt == 1);

    return 0;
}

void deleteNthElement()
{
    if(head != 0)
    {
        int p = 1, pos;
        printf("Enter a position b/w 1 and %d, where you wanna delete an element : ", n);
        scanf("%d", &pos);

        if(pos > n)
        {
            printf("\nInvalid position");
            return;
        }
        
        temp = head;
        if(n == 1)
        {
            newNode = temp;
            head = 0;
        }
        else if(pos == 1)
        {
            newNode = temp;
            head = head->next;
            n--;
        }
        else if(pos)
        {
            for(i = 1; i < pos-1; i++)
            {
                temp = temp->next;
            }
            newNode = temp->next;
            temp->next = newNode->next;
            n--;
        }

        free(newNode);
        display();
    }

    if(head == 0)
    {
        printf("\nNo element in the linked list.");
        exit(1);
    }
}

void insertAtTheEnd()
{
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