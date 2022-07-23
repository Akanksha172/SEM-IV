//============================================================================
// Name        : 21468_assignment02.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
using namespace std;

class Node
{
    string keyword;
    string meaning;
    Node *lchild;
    Node *rchild;

public:
    Node()
    {
        lchild=rchild=NULL;
    }
    Node(string s1,string s2)
    {
        keyword=s1;
        meaning=s2;
        lchild=rchild=NULL;
    }
    friend class BST;
};

class BST
{
    Node *root;

public:
    BST()
    {
        root==NULL;
    }

    void create(Node *&loc,Node *&par)
    {
        int n;
        string a1,a2;
    	cout<<"Enter the no. of nodes in binary tree : ";
    	cin>>n;

    	for(int i=0;i<n;i++)
     	{
    		cout<<"Enter the keyword : ";
     	    cin>>a1;
    	    cout<<"Enter the meaning : ";
    	    cin>>a2;
     	    insert(a1,a2,loc,par);
    	}
    }

    void search(string key,int &count,Node *&loc,Node *&par)
    {
    	count=0;
        Node *t;
        if(root==NULL)
        {
            cout<<"Tree does not exist"<<endl;
            loc=par=NULL;
        }
        loc=par=NULL;
        t=root;
        while(t!=NULL)
        {
            if(key == t->keyword)
            {
                loc=t;
                cout<<par<<loc;
                count++;
                break;
            }
            else if(key < t->keyword)
            {
                par=t;
                t=t->lchild;
                count++;
            }
            else
            {
                par=t;
                t=t->rchild;
                count++;
            }
        }
        if(loc==NULL)
        {
            cout<<"Key not found"<<endl;
        }
        else if(loc==t)
        {
            cout<<"Key found"<<endl;
        }
    }

    void insert(string key,string value,Node *&loc,Node *&par)
    {
    	int count=0;
    	search(key,count,loc,par);
    	if(loc!=NULL)
    	{
             cout<<"Node already exists"<<endl;
        }
    	Node *newNode =new Node(key,value);
    	newNode->keyword=key;
    	newNode->lchild=NULL;
    	newNode->rchild=NULL;

    	if(par==NULL)
    	{
    		root=newNode;
    	}
    	else if(newNode->keyword < par->keyword)
    	{
    		par->lchild=newNode;
    	}
    	else
    	{
    		par->rchild=newNode;
    	}
    }

    void inorderTraversal(Node *t)
    {
        if(t!=NULL)
        {
            inorderTraversal(t->lchild);
            cout<<t->keyword<<" ";
            inorderTraversal(t->rchild);
        }
    }

    void inorder()
    {
        cout<<"Inorder : ";
        inorderTraversal(root);
        cout<<endl;
    }

    void deleteBST1(string key,Node *&loc,Node *&par)
    {
        Node *child;
        if(loc->lchild==NULL && loc->rchild==NULL)
        {
            child=NULL;
        }
        else if(loc->lchild!=NULL)
        {
            child=loc->lchild;
        }
        else
        {
            child=loc->rchild;
        }
        if(par!=NULL)
        {
            if(loc=par->lchild)
            {
                par->lchild=child;
                delete loc;
            }
            else
            {
                par->rchild=child;
                delete loc;
            }
        }
        else
        {
            root=child;
            delete loc;
        }
    }

    void deleteBST2(string key,Node*&loc,Node*&par)
    {
        Node *ptr1,*ptr2;
        ptr1=loc;
        ptr2=loc->rchild;
        while(ptr2->lchild!=NULL)
        {
            ptr1=ptr2;
            ptr2=ptr2->lchild;
        }
        loc->keyword=ptr2->keyword;
        loc->meaning=ptr2->meaning;
        deleteBST1(key,ptr2,ptr1);
    }

    void deleteBST(Node *&loc,Node *&par)
    {
        int count=0;
        string key;
        cout<<"Enter the keyword to be deleted : ";
        cin>>key;
        search(key,count,loc,par);
        if(loc==NULL)
        {
            cout<<"Tree does not exists"<<endl;
        }
        if(loc->lchild!=NULL && loc->rchild!=NULL)
        {
            deleteBST2(key,loc,par);
        }
        else
        {
            deleteBST1(key,loc,par);
        }
    }
};

int main()
{
    BST b1;
    Node *loc,*par;
    string a1,a2,a3;
    int count;
    int choice;

    do
    {
        cout<<"\n\tMENU : "<<endl;
        cout<<"\n\t1.Create Binary Search Tree \n\t2.Traverse the Binary Search Tree \n\t3.Insert any node in Binary Search Tree \n\t4.Search any node in Binary Search Tree \n\t5.Delete any node in Binary Search Tree"<<endl;
        cout<<endl;

        cout<<"Enter your choice : ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                b1.create(loc,par);
                break;

            case 2:
                b1.inorder();
                break;

            case 3:
             	cout<<"Enter the keyword : ";
             	cin>>a1;
             	cout<<"Enter the meaning : ";
             	cin>>a2;
             	b1.insert(a1,a2,loc,par);
                break;

            case 4:
                cout<<"Enter the keyword to be searched : ";
             	cin>>a3;
                b1.search(a3,count,loc,par);
                cout<<count;
                break;

            case 5:
                b1.deleteBST(loc,par);
                if(loc==NULL)
                {
                    cout<<endl;
                }
                else
                {
                    cout<<"Keyword deleted successfully !";
                    cout<<endl;
                }
                break;
        }
    } while (choice!=0);

return 0;
}
