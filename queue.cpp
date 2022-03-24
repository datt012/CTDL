#include<iostream>
#include<stdlib.h>
using namespace std;

int queue[100];
int front=0,rear=0;
int m,n;

int empty()
{
    if (front>rear) return 1;
    else return 0;
}
void push(int value)
{
    if (empty()==1)
    {
        cout<<"Can't push";
    }
    else 
    {
        queue[rear]=value;
        rear++;
    }
}
void pop()
{
    front++;
}
void print()
{
    for (int i=front;i<rear;i++)
    {
        cout<<queue[i];
    }
}
int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    pop();
    pop();
    print();
}