#include<iostream>
using namespace std;

class Node
{
    int data;
    Node *lchild,*rchild;
    int lbit,rbit;

public:
    Node()
    {
        data=0;
        lchild=rchild=NULL;
        lbit=rbit=1;
    }
    Node(int x)
    {
        data=x;
        lchild=rchild=NULL;
        lbit=rbit=1;
    }
    friend class TBT;
};

class TBT
{
    Node *root;
    Node *header;

public: 
    TBT()
    {
        root=NULL;
        header=NULL;
    }

    void insert(int key)
    {
        // int key;
        if(root==NULL)
        {
            header = new Node(-99);
            header->lbit=0;
            header->rbit=0;
            header->rchild=header;
            root = new Node(key);
            root->lbit=0;
            root->rbit=0;
            root->lchild=header;
            root->rchild=header;
            header->lchild=root;
        }
        else
        {
            Node *ptr,*temp; 
            ptr=root;
            temp=new Node(key);
            while(1)
            {
                if(ptr->data > key)
                {
                    if(ptr->lbit != 0)
                    {
                        ptr=ptr->lchild;
                    }
                    else
                    {
                        temp->lbit=0;
                        temp->rbit=0;
                        temp->lchild=ptr->lchild;
                        temp->rchild=ptr;
                        ptr->lchild=temp;
                        ptr->lbit=1;
                        return;
                    }
                }
                else
                {
                    if(ptr->rbit !=0)
                    {
                        ptr=ptr->rchild;
                    }
                    else
                    {
                        temp->lbit=0;
                        temp->rbit=0;
                        temp->lchild=ptr;
                        temp->rchild=ptr->rchild;
                        ptr->rchild=temp;
                        ptr->rbit=1;
                        return;
                    }
                }
            }
        }
    }

    void inorderTraversal()
    {
        Node *t;
        t=root;
        while(t->lbit!=0)
        {
            t=t->lchild;
        }
        while(t!=header)
        {
            cout<<t->data<<" ";
            if(t->rbit!=0)
            {
                t=t->rchild;
                while(t->lbit!=0)
                {
                    t=t->lchild;
                }
            }
            else
            {
                t=t->rchild;
            }
        }
    }

    void preorderTraversal()
    {
        Node *t;
        t=root;
        while(t!=header)
        {
            cout<<t->data<<" ";
            if(t->lbit==1)
            {
                t=t->lchild;
            }
            else
            {
                if(t->rbit==1)
                {
                    t=t->rchild;
                }
                else
                {
                    while(t->rbit!=1)
                    {
                        t=t->rchild;
                    }
                    t=t->rchild;
                }
            }
        }
    }
};

int main()
{
    TBT t;
    cout<<"hello world"<<endl;
    t.insert(4);
    t.insert(6);
    t.insert(7);
    t.inorderTraversal();
    t.preorderTraversal();
    return 0;
}