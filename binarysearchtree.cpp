#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<math.h>
using namespace std;
int a[100][2];
int z=0;
struct treenode{
    int data;
    struct treenode *left;
    struct treenode *right;
    struct treenode *parent;
};
typedef struct treenode *tree;
tree makenode(int value)
{
    tree newnode;
    newnode=(tree)malloc(sizeof(struct treenode));
    newnode->data=value;
    newnode->left=NULL;
    newnode->right=NULL;
    newnode->parent=NULL;
    return newnode;
}
tree insert(tree root,int value)
{
    tree m=root;
    if (root==NULL)
    {
        tree newnode=makenode(value);
        root=newnode;
    }
    else
    {
        if(root->data>value)
        {
            if(root->left==NULL)
            {
                tree newnode=makenode(value);
                root->left=newnode;
                newnode->parent=root;
                a[z][0]=root->data;
                a[z][1]=newnode->data;
                z++;
            }
            else
            {
                root->left=insert(root->left,value);
            }
        }
        if(root->data<value)
        {
            if(root->right==NULL)
            {
                tree newnode=makenode(value);
                root->right=newnode;
                newnode->parent=root;
                a[z][0]=root->data;
                a[z][1]=newnode->data;
                z++;
            }
            else
            {
                root->right=insert(root->right,value);
            }
        }
    }
    return root;
}
tree Insert(tree root,int value)
{
    tree m=root;
    if (root==NULL)
    {
        tree newnode=makenode(value);
        root=newnode;
    }
    else
    {
        if(root->data<value)
        {
            if(root->left==NULL)
            {
                tree newnode=makenode(value);
                root->left=newnode;
                newnode->parent=root;
                a[z][0]=root->data;
                a[z][1]=newnode->data;
                z++;
            }
            else
            {
                root->left=insert(root->left,value);
            }
        }
        if(root->data>value)
        {
            if(root->right==NULL)
            {
                tree newnode=makenode(value);
                root->right=newnode;
                newnode->parent=root;
                a[z][0]=root->data;
                a[z][1]=newnode->data;
                z++;
            }
            else
            {
                root->right=insert(root->right,value);
            }
        }
    }
    return root;
}
void print(tree root)
{
    if (root!=NULL)
    {
        print(root->left);
        print(root->right);
        cout<<root->data<<endl;
    }
}
tree find(tree root,int value)
{
    if (root->data!=value)
    {
        if(root->data>value)
        {
            root=find(root->left,value);
        }
        if(root->data<value)
        {
            root=find(root->right,value);
        }
    }
    return root;
}
int min(tree root)
{
    tree p=root;
    while(p->left!=NULL)
    {
        p=p->left;
    }
    return p->data;
}
int max(tree root)
{
    tree p=root;
    while(p->right!=NULL)
    {
        p=p->right;
    }
    return p->data;
}
int successor(tree node)
{
    int a;
    if (node->right!=NULL)
    {
        a=min(node->right);
    }
    if (node->right==NULL&&node->left!=NULL)
    {
        a=node->data;
    }
    if (node->right==NULL&node->left==NULL)
    {
        while (node->left==NULL)
        {
            node=node->parent;
        }
        a=node->data;
    }
    return a;
}
int predessor(tree node)
{
    int a;
    if (node->left!=NULL)
    {
        a=max(node->left);
    }
    if (node->left==NULL&&node->right!=NULL)
    {
        a=node->data;
    }
    if (node->left==NULL&node->right==NULL)
    {
        while(node->right==NULL)
        {
            node=node->parent;
        }
        a=node->data;
    }
    return a;
}
int countnode(tree root,int k)
{
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        int a=countnode(root->left,k);
        int b=countnode(root->right,k);
        if(root->data<k) return a+b+1;
        else return a+b;
    }
}
int depth(tree root)
{
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        int a=depth(root->left);
        int b=depth(root->right);
        if (a>b) return a+1;
        else return b+1;
    }
}
int leaf(tree root)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->left==NULL&&root->right==NULL)
    {
        return 1;
    }
    else
    {
        int a=leaf(root->left);
        int b=leaf(root->right);
        return a+b;
    }
}
int height(tree root)
{
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        int a=height(root->left);
        int b=height(root->right);
        return 1+max(a,b);
    }
}
int lenumber(tree root)
{
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        int a=lenumber(root->left);
        int b=lenumber(root->right);
        if((root->data)%2==1) return root->data+a+b;
        return a+b;
    }
}
int evenmax(tree root)
{
    tree p=root,i;
    while(p!=NULL)
    {
        if((p->data)%2==0)
        {
            i=p;
        }
        p=p->right;
    }
    return i->data;
}
bool isleft(tree root,int value)
{
    if(root==NULL)
    {
        return true;
    }
    else
    {
        if(root->data<value) return false;
        else return isleft(root->left,value)&&isleft(root->right,value);
    }
    
}
bool avl(tree root)
{
    if(root==NULL)
    {
        return true;
    }
    else
    {
        int a=height(root->left);
        int b=height(root->right);
        if(abs(a-b)>1) return false;
        else return avl(root->left)&&avl(root->right);
    }
}
int isbst(tree root)
{
    if(root==NULL)
    {
        return 1;
    }
    if(root->left->data>root->data||root->right->data<root->data)
    {
        return 0;
    }
    return isbst(root->left)&&isbst(root->right);
} 
int diameter(tree root)
{
    if (root==NULL)
    {
        return 0;
    }
    else
    {
        int lh=height(root->left);
        int rh=height(root->right);
        int ld=diameter(root->left);
        int rd=diameter(root->right);
        return max(1+lh+rh,max(ld,rd));
    }
}
int main ()
{
    tree root=NULL;
    root=insert(root,25);
    root=insert(root,15);
    root=insert(root,50);
    root=insert(root,12);
    root=Insert(root,22);
    root=insert(root,31);
    root=insert(root,71);
    root=insert(root,35);
    root=insert(root,10);
    root=insert(root,18);
    root=insert(root,24);
    root=insert(root,40);
    root=insert(root,44);
    root=insert(root,66);
    root=insert(root,93);
    ofstream treegraph("treegraph.dot");
    treegraph<<"graph{"<<"\n"<<endl;
    for (int i=0;i<z;i++)
    {
        treegraph<<a[i][0]<<"--"<<a[i][1]<<";"<<"\n"<<endl;
    }
    treegraph<<"}";
    treegraph.close();
    int u=isbst(root);
    cout<<u<<endl;
}
