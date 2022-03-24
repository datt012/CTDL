#include<iostream>
using namespace std;

void merge(int a[],int l,int m,int r)
{
    int n1,n2;
    n1=m-l+1;
    n2=r-m;
    int L[n1],R[n2];
    int i,j,k;
    for (i=0;i<n1;i++)
    {
        L[i]=a[l+i];
    }
    for (j=0;j<n2;j++)
    {
        R[j]=a[m+1+j];
    }
    i=0;j=0;k=l;
    while(i<n1&&j<n2)
    {
        if(L[i]<R[j])
        {
            a[k]=L[i];
            i++;
        }
        else
        {
            a[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        a[k]=L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        a[k]=R[j];
        j++;
        k++;
    }
}
void mergesoft(int a[],int l,int r)
{
    if(l<r)
    {
        int m=(l+r)/2;
        mergesoft(a,l,m);
        mergesoft(a,m+1,r);
        merge(a,l,m,r);
    }
}
int main()
{
    int arr[]={8,2,9,4,5,3,1,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    mergesoft(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
}