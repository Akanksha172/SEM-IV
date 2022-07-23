#include <iostream>
using namespace std;
#define MAX 100

class node
{
    int data;
    node *lchild;
    node *rchild;
    
public:
    node()
    {
        data=0;
        lchild=rchild=NULL;
    }
    node(int x)
    {
        data=x;
        lchild=rchild=NULL;
    }
    friend class tree;
    friend class stack;
};

class stack
{
    int top;
    node *s[MAX];

public:
    stack()
    {
        top=-1;
    }
    
    int isempty()
    {
        if(top==-1) return 1;
        else return 0;
    }
    
    int isfull()
    {
        if(top==MAX-1) return 1;
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
            y= new node(x);
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
            if(ans=='r')
            {
                t->rchild=insert(t->rchild,x);
            }
        }
        return t;
    }
    
    void inorder(node *t)
    {
        if(t!=NULL)
        {
            inorder(t->lchild);
            cout<<t->data<<" ";
            inorder(t->rchild);
        }
    }
    
    void dummy1()
    {
        inorder(root);
    }
    
    void preorder(node *t)
    {
        if(t!=NULL)
        {
            cout<<t->data<<" ";
            preorder(t->lchild);
            preorder(t->rchild);
        }
    }
    
    void dummy2()
    {
        preorder(root);
    }
    
    void postorder(node *t)
    {
        if(t!=NULL)
        {
            postorder(t->lchild);
            postorder(t->rchild);
            cout<<t->data<<" ";
        }
    }
    
    void dummy3()
    {
        postorder(root);
    }
    
    void noninorder()
    {
        stack s1;
        node *t;
        t=root;
        while(1)
        {
            while(t!=NULL)
            {
                s1.push(t);
                t=t->lchild;
            }
            if(s1.isempty())
            {
                return;
            }
            t=s1.pop();
            cout<<t->data<<" ";
            t=t->rchild;
        }
    }
    
    void nonpreorder()
    {
        stack s1;
        node *t;
        t=root;
        while(1)
        {
            
            while(t!=NULL)
            {
                cout<<t->data<<" ";
                if(t->rchild!=NULL)
                {
                    s1.push(t->rchild);
                }
                t=t->lchild;
            }
            if(s1.isempty())
            {
                return;
            }
            t=s1.pop();
        }
    }

    int height(node *t)
    {
        int h1,h2;
        if(t==NULL || (t->lchild==NULL && t->rchild==NULL))
        {
            return 0;
        }
        h1=height(t->lchild);
        h2=height(t->rchild);
        if(h1>h2)
        {
            return (1+h1);
        }
        else
        {
            return(1+h2);
        }
    }

    int hi()
    {
        int x=height(root);
        return x;
    }

    int treeHeight(node* t)
	{
		int h1,h2;
		if(t==NULL || (t->lchild==NULL && t->rchild==NULL))
		{
			return 0;
		}
		h1=treeHeight(t->lchild);
		h2=treeHeight(t->rchild);
		if(h1>h2)
		{
			return (1+h1);
		}
		else
		{
			return (1+h2);
		}
	}

	int height1()
	{
		int x=treeHeight(root);
		return x;
	}

    void delete1(node *t)
    {
        if(t!=NULL)
        {
            delete1(t->lchild);
            delete1(t->rchild);
            delete t;
        }
    }

    void del()
    {
        delete1(root);
        cout<<"tree deleted";
        dummy1();
    }
};

int main()
{
    tree t;
    
    int a;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        t.create(a);
    }
    t.dummy1();
    // t.dummy2();
    // t.dummy3();
    cout<<endl;
    // t.noninorder();
    // t.nonpreorder();
    // t.hi();
    // t.height1();
    t.del();
    return 0;
}
