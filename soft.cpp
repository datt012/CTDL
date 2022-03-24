#include<iostream>
#include<stdlib.h>
using namespace std;

int a[100]={32,14,67,89,45,11,64,32,100,95};
int arr[100];
void insertionsoft(int a[],int size)
{
    int last,j;
    for (int i=0;i<size;i++)
    {
        last=a[i];
        j=i;
        while (last<a[j-1])
        {
            a[j]=a[j-1];
            j=j-1;
            a[j]=last;
        }
    }
}
void selectionsoft(int a[],int size)
{
    int min,u;
    for (int i=0;i<size-1;i++)
    {
        min=i;
        for (int j=i+1;j<size;j++)
        {
            if (a[min]>a[j])
            {
                u=a[min];
                a[min]=a[j];
                a[j]=u;
            }
        }
    }
}
int main()
{
    insertionsoft(a,10);
    for (int i=0;i<9;i++)
    {
        cout<<a[i]<<endl;
    }
}