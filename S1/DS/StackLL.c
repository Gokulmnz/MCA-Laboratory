#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *Next;
} node;

node *top = NULL, *new, *temp, *head;
int max, count;

int IsEmpty()
{
    if (count == 0)
        return 0;
    else
        return 1;
}

int IsFull()
{
    temp = head;
    if (IsEmpty() != 0)
    {
        for (temp = head, count = 0; temp != NULL; temp = temp->Next)
        {
            count++;
        }
    }
    if (count == max)
        return 0;
    else
        return 1;
}

void push()
{
    printf("Enter the Data to be Pushed : ");
    new = (struct Node *)malloc(sizeof(struct Node));
    scanf("%d", &new->data);
    new->Next = NULL;
    if (IsEmpty() == 0)
    {
        top = new;
        head = top;
        count++;
    }
    else if (IsFull() == 0)
    {
        printf("Error : Stack Overflow !");
    }
    else
    {
        top->Next = new;
        top = new;
        count++;
    }
}

void pop()
{
    if (IsEmpty() == 0)
    {
        printf("Error : Stack Underflow!");
    }
    else
    {
        for (temp = head; temp != top; temp = temp->Next)
        {
            if (temp->Next == top)
            {
                top = temp;
                temp = temp->Next;
                top->Next = NULL;
                break;
            }
        }
        free(temp);
        count--;
    }
}

void display()
{
    if (IsEmpty() == 0)
        printf("Error : Stack UnderFlow !");
    else
    {
        for (temp = head; temp != NULL; temp = temp->Next)
        {
            printf("%d\t", temp->data);
        }
    }
}

void main()
{
    int choose;
    printf("Enter Maximum number of Stack : ");
    scanf("%d", &max);
    while (1)
    {
        printf("\n1. Display the Stack\n2. Push Operation\n3. Pop Operation\n4. Checking Overflow\n5. Checking Underflow\n6. Display Top Element\n7. Display Number of Elements in the Stack\nChoose : ");
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
            display();
            break;

        case 2:
            push();
            break;
        case 3:
            pop();
            break;
        case 4:
            if (IsFull() == 0)
                printf("Stack is in Overflow Condition");
            else
                printf("The Stack is Not Full");
            break;
        case 5:
            if (IsEmpty() == 0)
                printf("The Stack is in Underflow Condition");
            else
                printf("The Stack is not Empty");
            break;
        case 6:
            printf("Top data in your Data : %d", top->data);
            break;
        case 7:
            IsFull();
            printf("Number of elements in your Stack is %d", count);
            break;
        default:
            break;
        }
    }
}