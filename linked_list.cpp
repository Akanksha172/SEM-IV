#include <iostream>

using namespace std;

class Node
{
      int data;
      Node *next;

public:
      Node()
      {
            data = 0;
            next = NULL;
      }
      Node(int x)
      {
            data = x;
            next = NULL;
      }
      friend class SLL;
};

class SLL
{
      Node *head;

public:
      SLL()
      {
            head = NULL;
      }

      void create();
      void display();
      void insertAtBegin();
      void insertAtEnd();
      void insertAfter();
      void deletion();
      void search();
};

void SLL::create()
{
      int x;
      char ans;
      Node *New, *temp;

      do
      {
            cout << "Enter the element : ";
            cin >> x;
            New = new Node(x);

            if (head==NULL)
            {
                  head = New;
                  temp = head;
            }
            else
            {
                  temp->next = New;
                  temp = New;
            }
            cout << "Do you want to enter more elements ? (1/0) : ";
            cin >> ans;
      } while (ans == '1');
}

void SLL::display()
{
      Node *ptr=head;
      
      if (ptr == NULL)
      {
            cout << "List is empty" << endl;
      }
      cout << "Created list is : ";
      while (ptr != NULL)
      {
            cout << ptr->data << " ";
            ptr = ptr->next;
      }
      cout<<endl;
}

void SLL::insertAtBegin()
{
    Node *t,*ptr;
    int data;
    t=new Node(data);
    cout<<"Enter the element to be inserted : ";
    cin>>t->data;
    if(head==NULL)
    {
        head=t;
    }
    else
    {
        ptr=head;
        t->next=ptr;
        head=t;
    }
    display();
}

void SLL::insertAtEnd()
{
    Node *t,*ptr;
    int data;
    t=new Node(data);
    cout<<"Enter the element to be inserted : ";
    cin>>t->data;
    if(head==NULL)
    {
        head=t;
    }
    else
    {
        ptr=head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=t;
        t->next=NULL;
    }
    display();
}

void SLL::insertAfter()
{
    int key,data;
    Node *t,*ptr;
    t=new Node(data);
    cout<<"Enter the element to be inserted : ";
    cin>>t->data;
    if(head==NULL)
    {
        head=t;
    }
    else
    {
        cout<<"Enter the element after which new element is to be inserted : ";
        cin>>key;
        ptr=head;
        do
        {
            if(ptr->data==key)
            {
                t->next=ptr->next;
                ptr->next=t;
                break;
            }
            else
            {
                ptr=ptr->next;
            }
        } while (ptr!=NULL);        
    }
    display();
}

void SLL::deletion()
{
    Node *t,*prev;
    int key;
    t=head;
    cout<<"Enter the element which is to be deleted : ";
    cin>>key;
    while(t!=NULL)
    {
        if(t->data==key)
        {
            break;
        }
        prev=t;
        t=t->next;
    }
    if(t==NULL)
    {
        cout<<"Node not found";
    }
    else
    {
        if(t==head)
        {
            head=t->next;
        }
        else
        {
            prev->next=t->next;
        }
        delete t;
    }
    display();
}

void SLL::search()
{
    Node *ptr;
    int flag;
    ptr=head;
    int key;
    cout<<"Enter the element which is to be searched : ";
    cin>>key;
    if(ptr==NULL)
    {
        cout<<"List is empty !";
    }
    flag=0;
    while(ptr!=NULL && flag==0)
    {
        if(ptr->data!=key)
        {
            ptr=ptr->next;
        }
        else
        {
            flag=1;
        }
        if(flag==1)
        {
            cout<<"Element found !";
        }
        else
        {
            cout<<"Element not found !";
        }
    }
}

int main()
{
      SLL s;
      s.create();
      s.display();
      s.insertAtBegin();
      s.insertAtEnd();
      s.insertAfter();
      s.deletion();
      s.search();
      return 0;
}