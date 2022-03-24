#include<iostream>
#include<stdlib.h>
using namespace std;

struct linkedlist{
    int data;
    struct linkedlist *next;
};
typedef struct linkedlist *node;

node createnode(int value)
{
    node newnode;
    newnode=(node)malloc(sizeof(struct linkedlist));
    newnode->data=value;
    newnode->next=NULL;
    return newnode;
}
node push(node head,int value)
{
    if(head==NULL)
    {
        node newnode;
        newnode=createnode(value);
        head=newnode;
    }
    else
    {
        head->next=push(head->next,value);
    }
    return head;
}
void print(node head)
{
    node p=head;
    while(p->next!=NULL)
    {
        cout<<p->data<<endl;
        p=p->next;
    }
    cout<<p->data;
}
int empty(node head)
{
    if(head==NULL)
    {
        return 0;
    }
    return 1;
}
node pop(node head)
{
    if(empty(head)==0)
    {
        cout<<"Can't delete";
    }
    else
    {
        if(head->next==NULL)
        {
            head=NULL;
            free(head);
        }
        else
        {
            head->next=pop(head->next);
        }
    }
    return head;
}
int main()
{
    node head=NULL;
    head=push(head,2);
    head=push(head,3);
    head=push(head,4);
    head=push(head,5);
    head=push(head,6);
    head=pop(head);
    print(head);
}
