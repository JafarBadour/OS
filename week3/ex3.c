
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
};

struct node * newList()
{
    struct node *l1 = malloc(sizeof(struct node));
    l1->next=NULL;
    return l1;
}


void insert_node(struct node *head, int v,int n)
{
    struct node *temp = head;

    for(int i=0; i<n; i++)
    {
        temp = temp->next;
        if(temp==NULL)
        {
            printf("ERROR %d",n);
            exit(0);
        }

    }

    if(temp->next==NULL)
    {
        temp->next = malloc(sizeof(struct node));
        temp->next->value = v;
        temp->next->next = NULL;
    }
    else
    {
        struct node *temp=temp->next;
        temp->next=malloc(sizeof(struct node));
        temp->next->value = v;
        temp->next->next=temp;
    }


}
void print(struct node *head)
{
    struct node *temp = head->next;

    while (temp != NULL)
    {
        printf("%d\n", temp->value);
        temp = temp->next;
    }
}


void delete_node(struct node *head, int n)
{
    struct node *temp = head;

    for(int i=0; i<n; i++)
    {
        temp = temp->next;
        if(temp==NULL)
        {
            printf("ERROR",n);
            return;
        }

    }
    if(temp->next->next==NULL)
    {
        temp->next = NULL;
    }
    else
    {
        temp->next=temp->next->next;
    }


}


int main()
{
    struct node *l1 = newList();

    insert_node(l1,44,0);
    insert_node(l1,1,1);
    delete_node(l1,1);

    print(l1);

    return 0;
};
