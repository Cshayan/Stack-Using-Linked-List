#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *next;
}*top=NULL;

void push(int val)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=val;
    temp->next=top;
    top=temp;
    printf("\nValue inserted\n");
}
int pop()
{
    if(top==NULL)
    {
        printf("\nList is empty\n");
        return -1;
    }
    struct node *temp=top;
    top=top->next;
    int val=temp->data;
    free(temp);
    return val;

}
int peek()
{
    if(top!=NULL)
        return (top->data);
    else
        return -1;
}
int main()
{
    int val,ch;
    while(1)
    {
        printf("\n1.Push");
        printf("\n2.Pop");
        printf("\n3.Peek");
        printf("\n4.Exit");
        printf("\nEnter your choice:- ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("\nEnter the value to be pushed:- ");
            scanf("%d",&val);
            push(val);
            break;
        case 2:
            val=pop();
            if(val!=-1)
            {
                printf("\nPopped value is %d",val);
            }
            break;
        case 3:
            val=peek();
            if(val!=-1)
            {
                 printf("\nThe topmost value is %d",val);
            }
            break;
        case 4:
            exit(0);
        }
    }
}

