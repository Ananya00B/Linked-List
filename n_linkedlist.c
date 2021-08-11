#include<stdio.h>
#include<stdlib.h>

void insertAtTheEnd();
void insertAtNthPlace();
void display();

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

    do{
        insertAtNthPlace();
        printf("\nDo you want to insert an another element at nth place in the linked list?\n", n+1);
        printf("Choose : 1 -> YES, any other no. -> NO : ");
        scanf("%d", &opt);
    }while(opt == 1);

    display();
    return 0;
}

void insertAtNthPlace()
{
    int p = 1, pos;
    printf("Enter a position b/w 1 and %d, where you wanna insert an element : ", n);
    scanf("%d", &pos);
    newNode = (struct node*) malloc(sizeof(struct node));
    printf("Enter the element to insert : ");
    scanf("%d", &newNode->data);

    int i;
    temp = head;
    if(pos == 1)
    {
        newNode -> next = temp;
        head = newNode;
        n++;
        return;
    }

    for(i = 1; i < pos-1; i++)  //moving to the (n-1)th position node in the linked list
    {
        temp = temp->next;
    }

    newNode->next = temp->next;  //Make the newNode point to next node of ptr temp
    temp->next = newNode;  	//Make ptr temp point to newNode in the linked list
    n++;
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