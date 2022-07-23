#include <iostream>
using namespace std;

class Node
{
    int data;
    Node *lchild, *rchild;

public:
    Node()
    {
        data=0;
        lchild=rchild=NULL;
    }
    Node(int x)
    {
        data=x;
        lchild=rchild=NULL;
    }
    friend class Stack1;
    friend class BST;
};

class Stack1
{
	int top;
	Node *s[20];

public:
	Stack1()
	{
		top=-1;
	}

	int isEmpty()
	{
		if(top==-1)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	void push(Node *x)
	{
		if(top==19)
		{
			cout<<"Stack Overflow"<<endl;
		}
		else
		{
			top++;
			s[top]=x;
		}
	}

	Node* pop()
	{
		Node *x;
		if(top==-1)
		{
			cout<<"Stack Underflow"<<endl;
		}
		else
		{
			x=s[top];
			top--;
		}
		return x;
	}
};

class BST
{
    Node* root;

public:
    BST()
    {
        root=NULL;
    }

    // void create(Node *&loc, Node *&par);
    // void search(int key, Node *&loc, Node *&par);
    // void insert(int key, Node *&loc, Node *&par);
    // void preorderTraversal(Node *t);
    // void preorder();
// };

    void create(Node *&loc, Node *&par)
    {
        int n;
        cout<<"Enter the no. of nodes in tree : ";
        cin>>n;
        int key;
        for(int i=0;i<n;i++)
        {
            cout<<"Enter the key : ";
            cin>>key;
            insert(key,loc,par);
        }
    }
    
    void search(int key, Node *&loc, Node *&par)
    {
        Node *t;
        if(root == NULL)
        {
            cout<<"Tree does not exist"<<endl;
            loc=par=NULL;
        }
        loc=par=NULL;
        t=root;
        while(t!=NULL)
        {
            if(key == t->data)
            {
                loc=t;
                // cout<<par<<loc;
                break;
            }
            else if(key < t->data)
            {
                par=t;
                t=t->lchild;
            }
            else
            {
                par=t;
                t=t->rchild;
            }
        }
        if(loc==NULL)
        {
            cout<<"Key does not found"<<endl;
        }
        else if(loc==t)
        {
            cout<<"Key found"<<endl;
        }
    }
    
    void insert(int key, Node *&loc, Node *&par)
    {
        search(key,loc,par);
        if(loc!=NULL)
        {
            cout<<"Node already exists"<<endl;
        }
        Node *newNode = new Node(key);
        newNode->data=key;
        newNode->lchild=NULL;
        newNode->rchild=NULL;
        if(par==NULL)
        {
            root=newNode;
        }
        else if(newNode->data < par->data)
        {
            par->lchild=newNode;
        }
        else
        {
            par->rchild=newNode;
        }
    }
    
    void preorderTraversal(Node *t)
    {
        if(t!=NULL)
        {
            cout<<t->data<<" ";
            preorderTraversal(t->lchild);
            preorderTraversal(t->rchild);
        }
    }
    
    void preorder()
    {
        cout<<"Preorder : ";
        preorderTraversal(root);
        cout<<endl;
    }

    void preorderTraversalNonRecursive()
	{
		Stack1 s;
		Node* t;
		t=root;
		cout<<"Preorder : ";
		while(1)
		{
			while(t!=NULL)
			{
				cout<<t->data<<" ";
				if(t->rchild !=NULL)
				{
					s.push(t->rchild);
				}
				t=t->lchild;
			}
			if(s.isEmpty())
			{
				return ;
			}
			t=s.pop();
		}
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
    int key;
    int choice;
    Node *loc,*par;
    BST b;

    do
    {
        cout<<"\nMenu \n1.Create \n2.Traverse \n3.Insert \n4.Search \n5.Delete"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        
        switch (choice)
        {
            case 1:
                b.create(loc,par);
                break;
            
            case 2:
                b.preorder();
                break;

            case 3:
                cout<<"Enter key to be inserted : ";
                cin>>key;
                b.insert(key,loc,par);
                break;
                
            case 4:
                b.search(key,loc,par);

            // default:
            //     break;
        }
    } while (choice!=0);
    return 0;
}
