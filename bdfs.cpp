 #include<iostream>
#include<stdlib.h>
using namespace std;

int a[100][100];
int b[100][100];
int visited[100]={0};
int m,n,g;
int queue[100];
int front=0,rear=-1;
int empty()
{
    int count=0;
    for (int i=front;i<=rear;i++)
    {
        count++;
    }
    if (count==0) return 1;
    else return 0;
}
void push(int value)
{
    rear++;
    queue[rear]=value;
}
void pop()
{
    front++;
}
void scan()
{
    cin>>n>>m;
    for (int i=0;i<m;i++)
    {
        cin>>a[i][0]>>a[i][1];
    }
}
void arr()
{
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            if (i==j)
            {
                b[i][j]=1;
            }
            else
            {
                b[i][j]=0;
            }
        }
    }
    for (int i=0;i<m;i++)
    {
        b[a[i][0]][a[i][1]]=1;
        b[a[i][1]][a[i][0]]=1;
    }
}
void dfs(int u)
{
    cout<<u<<" ";
    visited[u]=1;
    for (int i=1;i<=n;i++)
    {
        if (b[u][i]==1&&visited[i]==0)
        {
            dfs(i);
        }
    }
}
void bfs(int u)
{
    push(u);
    visited[u]=1;
    while(empty()==0)
    {
        int e=queue[front];
        cout<<e<<" ";
        pop();
        for (int i=1;i<=n;i++)
        {
            if (b[e][i]==1&&visited[i]==0)
            {
                push(i);
                visited[i]=1;
            }
        }
    }
}
int main()
{
    scan();
    arr();
    dfs(1);
}
