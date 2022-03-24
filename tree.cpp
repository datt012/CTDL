#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;
int a[100][2];
struct tnode {
    int data;
    struct tnode *left;
    struct tnode *right;
};
typedef struct tnode *treenode;

treenode makenode(int value)
{
    treenode newnode;
    newnode=(treenode)malloc(sizeof(struct tnode));
    newnode->data=value;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
treenode insert(treenode tree,int value,int z)
{
    treenode newnode,p;
    if (tree==NULL)
    {
        newnode=makenode(value);
        tree=newnode;
    }
    else
    {
        if (rand()%2==0)
        {
            if (tree->left==NULL)
            {
                newnode=makenode(value);
                tree->left=newnode;
                a[z][1]=tree->data;
                a[z][0]=newnode->data;
            }
            else
            {
                tree->left=insert(tree->left,value,z);
            }
        }
        else
        {
            if (tree->right==NULL)
            {
                newnode=makenode(value);
                tree->right=newnode;
                a[z][1]=tree->data;
                a[z][0]=newnode->data;
            }
            else
            {
                tree->right=insert(tree->right,value,z);
            }
        }
    }
    return tree;
}
void del(treenode tree)
{
    if (tree==NULL) return;
    del(tree->left);
    del(tree->right);
    free(tree);
    return;
}
void preorder(treenode tree)
{
    if (tree!=NULL)
    {
        cout<<tree->data<<" ";
        preorder(tree->left);
        preorder(tree->right);
    }
}
int depth(treenode tree)
{
    if (tree==NULL)
    {
        return 0;
    }
    else
    {
        int a=depth(tree->left);
        int b=depth(tree->right);
        if (a<b) return b+1;
        else return a+1;
    }
    
}
int main ()
{
    int i,n,m,z;
    treenode tree=NULL;
    for (i=0;i<7;i++)
    {
        cin>>n;
        tree=insert(tree,n,i);
    }
    preorder(tree);
    m=depth(tree);
    cout<<"\n"<<m<<endl;
    ofstream treegraph("treegraph.dot");
    treegraph<<"graph{"<<"\n"<<endl;
    for (i=1;i<7;i++)
    {
        treegraph<<a[i][1]<<"--"<<a[i][0]<<";"<<"\n"<<endl;
    }
    treegraph<<"}";
    treegraph.close();
    return 0;
}
    



