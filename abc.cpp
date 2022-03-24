#include<iostream>
using namespace std;
void swap(int &a,int &b)
{
    int t=a;
    a=b;
    b=t;
}
void merge(int a[],int l,int m,int r)
{
    int n1,n2;
    int i=0,j=0,k=0;
    n1=m-l+1;
    n2=r-m;
    int left[n1],right[n2];
    for (int r=0;r<n1;r++)
    {
        left[r]=a[l+r];
    }
    for (int r=0;r<n2;r++)
    {
        right[r]=a[m+1+r];
    }
    while(i<n1&&j<n2)
    {
        if (left[i]<right[j])
        {
            a[k]=left[i];
            i++;
        }
        if (left[i]>right[j])
        {
            a[k]=right[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        a[k]=left[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        a[k]=right[j];
        j++;
        k++;
    }
}
void divide(int a[],int l,int r)
{
    if (l<r)
    {
        int m=(l+(r-1))/2;
        divide(a,l,m);
        divide(a,m+1,r);
        merge(a,l,m,r);
    }
}
void print(int a[],int size)
{
    int i;
    for (i=0;i<size;i++)
    {
        cout<<a[i]<<endl;
    }
}
int main()
{
    int arr[]={13,92,81,43,31,57,26,75,65};
    int n = sizeof(arr)/sizeof(arr[0]);
    divide(arr,0,n-1);
    print(arr,n);
}