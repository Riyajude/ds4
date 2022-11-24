#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int info;
    struct node *ptr;
}*top,*top1,*temp;
 
int topelement();
void push(int data);
void pop();
void empty();
void display();
void create();
 
int count = 0;
 
void main()
{
    int no, ch, e;
    printf("\n---------Menu---------\n");
    printf("\n 1 - Push element");
    printf("\n 2 - Pop element");
    printf("\n 3 - Display Top element");
    printf("\n 4 - Check if stack empty");
    printf("\n 5 - Dipslay stack");
    printf("\n 6 - Exit");
 
    create();
 
    while (1)
    {
        printf("\n Enter choice : ");
        scanf("%d", &ch);
 
        switch (ch)
        {
        case 1:
            printf("Enter data : ");
            scanf("%d", &no);
            push(no);
            break;
        case 2:
            pop();
            break;
        case 3:
            if (top == NULL)
                printf("No elements in stack");
            else
            {
                e = topelement();
                printf("\n Top element : %d", e);
            }
            break;
        case 4:
            empty();
            break;
        case 5:
            display();
            break;
        case 6:
            printf("Terminating..");
            exit(0);
        
        default :
            printf(" Wrong choice, Please enter correct choice  ");
            break;
        }
    }
}
 
void create()
{
    top = NULL;
}

void push(int data)
{
    if (top == NULL)
    {
        top =(struct node *)malloc(1*sizeof(struct node));
        top->ptr = NULL;
        top->info = data;
    }
    else
    {
        temp =(struct node *)malloc(1*sizeof(struct node));
        temp->ptr = top;
        temp->info = data;
        top = temp;
    }
    count++;
}
 
void display()
{
    top1 = top;
 
    if (top1 == NULL)
    {
        printf("Stack is empty");
        return;
    }
 
    while (top1 != NULL)
    {
        printf("%d ", top1->info);
        top1 = top1->ptr;
    }
 }
 
void pop()
{
    top1 = top;
 
    if (top1 == NULL)
    {
        printf("\n Cannot pop from empty stack");
        return;
    }
    else
        top1 = top1->ptr;
    printf("\n Popped value : %d", top->info);
    free(top);
    top = top1;
    count--;
}
 
int topelement()
{
    return(top->info);
}
 
void empty()
{
    if (top == NULL)
        printf("\n Stack is empty");
    else
        printf("\n Stack is not empty with %d elements", count);
}
