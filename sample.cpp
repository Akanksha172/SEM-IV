/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;
#define max 100

class node
{
    int data;
    node *lchild;
    node *rchild;
    
public:
    node()
    {
        data=0;
        lchild=NULL;
        rchild=NULL;
    }
    node(int x)
    {
        data=x;
        lchild=NULL;
        rchild=NULL;
    }
    friend class tree;
    friend class stack;
};

class stack
{
    int top;
    node *s[max];
    
public:
    stack()
    {
        top=-1;
    }
    
    int isempty()
    {
        if (top==-1) return 1;
        else return 0;
    }
    
    int isfull()
    {
        if(top==max-1)
        {
            return 1;
        }
        else return 0;
    }
    
    void push(node *p)
    {
        if(isfull())
        {
            cout<<"stack is full";
        }
        else
        {
            top++;
            s[top]=p;
        }
    }
    
    node *pop()
    {
        node *p;
        if(isempty())
        {
            cout<<"stack is empty";
        }
        else
        {
            p=s[top];
            top--;
        }
        return p;
    }
};

class tree
{
    node *root;
    
public:
    tree()
    {
        root=NULL;
    }
    
    void create(int x)
    {
        node *y;
        if(root==NULL)
        {
            y=new node(x);
            root=y;
        }
        else
        {
            root=insert(root,x);
        }
    }
    
    node* insert(node *t,int x)
    {
        node *y;
        char ans;
        if(t==NULL)
        {
            y=new node(x);
            return y;
        }
        else
        {
            cout<<"l or r";
            cin>>ans;
            if(ans=='l')
            {
                t->lchild=insert(t->lchild,x);
            }
            else
            {
                t->rchild=insert(t->rchild,x);
            }
        }
        return t;
    }
    
    void in(node *t)
    {
        if(t!=NULL)
        {
            in(t->lchild);
            cout<<t->data<<" ";
            in(t->rchild);
        }
    }
    
    void dummy1()
    {
        in(root);
    }
    
    void pre(node *t)
    {
        if(t!=NULL)
        {
            cout<<t->data<<" ";
            pre(t->lchild);
            pre(t->rchild);
        }
    }
    
    void dummy2()
    {
        pre(root);
    }
    void post(node *t)
    {
        if(t!=NULL)
        {
            post(t->lchild);
            post(t->rchild);
            cout<<t->data<<" ";
        }
    }
    
    void dummy3()
    {
        post(root);
    }
};

int main()
{
    int n,a;
    cin>>a;
    tree h;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        h.create(a);
    }
    h.dummy1();
    h.dummy2();
    h.dummy3();
    cout<<endl;

    return 0;
}
