#include<iostream>
using namespace std;
int partition(int a[],int low,int high)
{
    int left=low;
    int right=high-1;
    int pivot=a[high];
    while (left<=right)
    {
        while (a[left]<pivot)
        {
            left++;
        }
        while (a[right]>pivot)
        {
            right--;
        }
        if (left>right) break;
        swap(a[left],a[right]);
        left++;
        right--;
    }
    swap(a[left],a[high]);
    return left;
}
void divide(int a[],int low,int high)
{
    if (low<high)
    {
        int p=partition(a,low,high);
        divide(a,low,p-1);
        divide(a,p+1,high);
    }
}
int main()
{
    int arr[]={13,92,81,43,31,57,26,75,65};
    int n=sizeof(arr)/sizeof(arr[0]);
    divide(arr,0,n-1);
    for (int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
}