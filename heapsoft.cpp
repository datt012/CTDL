#include<iostream>

using namespace std;

void heap(int a[],int n,int largest)
{
    int i=largest;
    int l=2*i+1;
    int r=2*i+2;
    if (l<n&&a[i]<a[l])
    {
        i=l;
    }
    if (r<n&&a[i]<a[r])
    {
        i=r;
    }
    if (i!=largest)
    {
        swap(a[i],a[largest]);
        heap(a,n,i);
    }
}
void heapsoft(int a[],int n)
{
    int i;
    for (i=n/2-1;i>=0;i--)
    {
        heap(a,n,i);
    }
    for(i=n-1;i>=0;i--)
    {
    swap(a[i],a[0]);
    heap(a,i,0);
    }
}
int main()
{
    int arr[]={13,92,81,43,31,57,26,75,65};
	int n=sizeof(arr)/sizeof(arr[0]);
    heapsoft(arr,n);
    for (int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
}