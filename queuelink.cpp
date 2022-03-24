#include<iostream>
#include<stdlib.h>
using namespace std;

struct linkedlist{
    int data;
    struct linkedlist *next;
    struct linkedlist *prev;
};
typedef struct linkedlist *node;
struct queue{
    node head;
    node tail;
};
int empty(queue &opp)
{
    if(opp.head==NULL)
    {
        return 0;
    }
    return 1;
}
node createnode(int value)
{
    node newnode;
    newnode=(node)malloc(sizeof(struct linkedlist));
    newnode->data=value;
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}
void init(queue &opp)
{
    opp.head=NULL;
    opp.tail=NULL;
}
void push(queue &opp,int value)
{
    node newnode;
    newnode=createnode(value);
    if(empty(opp)==0)
    {
        opp.head=newnode;
        opp.tail=opp.head;
    }
    else
    {
        opp.tail->next=newnode;
        newnode->prev=opp.tail;
        opp.tail=newnode;
    }
}
void pop(queue &opp)
{
    if(empty(opp)==0)
    {
        cout<<"Can't delete";
    }
    else
    {
        opp.head=opp.head->next;
        opp.head->prev=NULL;
        free(opp.head->prev);
    }
}
void print(queue &opp)
{
    node p=opp.head;
    while(p!=opp.tail)
    {
        cout<<p->data<<endl;
        p=p->next;
    }
    cout<<p->data<<endl;
}
int main()
{
    queue ios;
    init(ios);
    push(ios,2);
    push(ios,3);
    push(ios,4);
    push(ios,5);
    push(ios,6);
    pop(ios);
    push(ios,7);
    push(ios,8);
    pop(ios);
    print(ios);
}
