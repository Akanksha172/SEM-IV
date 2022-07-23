#include <iostream>
using namespace std;

class Node
{
	int data;
	Node *lchild;
	Node *rchild;

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
	friend class Tree;
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

class Tree
{
	Node *root;

public:
	Tree()
	{
		root=NULL;
	}

	void create(int x)
	{
		Node *newNode;

		if(root==NULL)
		{
			cout<<"The first data entered is root !"<<endl;
			newNode=new Node(x);
			root=newNode;
		}
		else
		{
			root=insert(root,x);
		}
	}

	Node* insert(Node *t,int x)
	{
		Node *newNode;
		char ans;

		if(t==NULL)
		{
			newNode=new Node(x);
			return newNode;
		}
		else
		{
			cout<<"Where do you want to insert ";
			cout<<x;
			cout<<" on left or right ?";
			cin>>ans;

			if(ans=='l' || ans=='L')
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

	void inorderTraversalRecursive(Node *t)
	{
		if(t!=NULL)
		{
			inorderTraversalRecursive(t->lchild);
			cout<<t->data<<" ";
			inorderTraversalRecursive(t->rchild);
		}
	}

	void inorder()
	{
		cout<<"Inorder : ";
		inorderTraversalRecursive(root);
		cout<<endl;
	}

	void preorderTraversalRecursive(Node *t)
	{
		if(t!=NULL)
		{
			cout<<t->data<<" ";
			preorderTraversalRecursive(t->lchild);
			preorderTraversalRecursive(t->rchild);
		}
	}

	void preorder()
	{
		cout<<"Preorder : ";
		preorderTraversalRecursive(root);
		cout<<endl;
	}

	void postorderTraversalRecursive(Node *t)
	{
		if(t!=NULL)
		{
			postorderTraversalRecursive(t->lchild);
			postorderTraversalRecursive(t->rchild);
			cout<<t->data<<" ";
		}
	}

	void postorder()
	{
		cout<<"Postorder : ";
		postorderTraversalRecursive(root);
		cout<<endl;
	}

	void inorderTraversalNonRecursive()
	{
		Stack1 s;
		Node *t;
		t=root;
		cout<<"Inorder : ";
		while(1)
		{
			while(t!=NULL)
			{
				s.push(t);
				t=t->lchild;
			}
			if(s.isEmpty())
			{
				return;
			}
			t=s.pop();
			cout<<t->data<<" ";
			t=t->rchild;
		}
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

	void postorderTraversalNonRecursive()
	{
		Stack1 s;
		Node *temp,*p,*t;
		t=root;
		temp = new Node('#');
		cout<<"Postorder : ";
		while(1)
		{
			while(t!=NULL)
			{
				s.push(t);
				if(t->rchild!=NULL)
				{
					s.push(t->rchild);
					s.push(temp);
				}
				t=t->lchild;
			}
			if(s.isEmpty())
			{
				return ;
			}
			else
			{
				p=s.pop();
			}
			while(p!=temp && !s.isEmpty())
			{
				cout<<p->data<<" ";
				p=s.pop();
			}
			if(!s.isEmpty())
				{
					t=s.pop();
				}
			else
			{
				if(p!=temp)
				{
					cout<<p->data<<" ";
				}
			}

		}
		cout<<endl;
	}

	void mirrorImage(Node* t)
	{
		Node* temp;
		if(t!=NULL)
		{
			mirrorImage(t->lchild);
			mirrorImage(t->rchild);
			temp=t->lchild;
			t->lchild=t->rchild;
			t->rchild=temp;
		}
	}

	void mirror()
	{
		mirrorImage(root);
	}

	Node* copyTree(Node* t)
	{
		Node* temp=NULL;
		if(t!=NULL)
		{
			temp=new Node(t->data);
			temp->lchild=copyTree(t->lchild);
			temp->rchild=copyTree(t->rchild);
		}
		return temp;
	}

	void copy()
	{
		copyTree(root);
	}

	int internalNodes(Node* t)
	{
		if(t==NULL || (t->lchild==NULL && t->rchild==NULL))
		{
			return 0;
		}
		else
		{
			return 1+internalNodes(t->lchild)+internalNodes(t->rchild);
			cout<<t->data;
		}
	}

	int leafNodes(Node* t)
	{
		int count = 0;
		if(root != t)
		{
			leafNodes(t->lchild);
			if((t->lchild == NULL) || (t->rchild == NULL))
			{
				count++;
			}
			leafNodes(t->lchild);
			cout<<t->data;
		}
		return count;
	
	}

	int leafAndInternalNodes()
	{
		int x=leafNodes(root);
		int y=internalNodes(root);
		return x and y;
	}

	int treeHeight(Node* t)
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

	int height()
	{
		int x=treeHeight(root);
		return x;
	}

	void deleteTree(Node* t)
	{
		if(t!=NULL)
		{
			deleteTree(t->lchild);
			deleteTree(t->rchild);
			// cout<<t->data;
			delete t;
		}
	}

	void deleteTree1()
	{
		deleteTree(root);
	}
};


int main()
{
	Tree t1;
	int n,a;
	int choice;

	do
	{
		cout<<"\n\tMENU"<<endl;
		cout<<"\n\t1.Create the tree\n\t2.Traverse the tree recursively\n\t3.Traverse the tree non recursively\n\t4.Mirror Image\n\t5.Copy Tree\n\t6.Count Internal and leaf nodes\n\t7.Height of the tree\n\t8.Delete the tree"<<endl;
		cout<<" "<<endl;

		cout<<"Enter your choice : ";
		cin>>choice;

		switch (choice)
		{
			case 1:
				cout<<"Enter the no. of nodes in binary tree : ";
				cin>>n;

				for(int i=0;i<n;i++)
				{
					cout<<"Enter the data : ";
					cin>>a;
					t1.create(a);
				}
				break;

			case 2:
				t1.inorder();
				t1.preorder();
				t1.postorder();
				break;

			case 3:
				t1.inorderTraversalNonRecursive();
				t1.preorderTraversalNonRecursive();
				t1.postorderTraversalNonRecursive();
				break;

			case 4:
				t1.mirror();
				break;

			case 5:
				t1.copy();
				break;

			case 6:
				cout<<t1.leafAndInternalNodes();
				break;

			case 7:
				cout<<t1.height();
				break;

			case 8:
				t1.deleteTree1();
				break;

			default:
				cout << "Please enter a valid choice";
				break;


		}
		cout<<"\nDo you want to continue?{1/0)";
		cin>>choice;
	} while (choice!=0);

	return 0;
}
