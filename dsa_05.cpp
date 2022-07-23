#include <iostream>
using namespace std;

class node
{
    string key;
    string value;
    node *next;

public:
    node()
    {
        key = "";
        value = "";
        next = NULL;
    }
    node(string k, string v)
    {
        key = k;
        value = v;
        next = NULL;
    }
    friend class hash_table;
};

class hash_table
{
    int s;
    node **table;   

public:
    hash_table()
    {
        cout<<"Enter size for table: ";
        cin>>s;
        table=new node *[s];
        for (int i = 0; i < s; i++)
        {
            table[i] = NULL;
        }
    }
    int hash_func(string k)
    {
        return k[0] % s;
    }
    void insert(string k, string v)
    {
        int index = hash_func(k);
        if (table[index] == NULL)
        {
            table[index] = new node;
            table[index]->key = k;
            table[index]->value = v;
            table[index]->next = NULL;
        }
        else
        {
            node *temp = new node;
            temp = table[index];
            if(temp->key==k)
                {
                    temp->value=v;
                    cout<<"Value Updated!!!"<<endl;
                    return;
                }
            while (temp->next != NULL)
            {
                if(temp->key==k)
                {
                    temp->value=v;
                    cout<<"Value Updated!!!"<<endl;
                    return;
                }
                temp = temp->next;
            }
            temp->next = new node;
            temp->next->key = k;
            temp->next->value = v;
            temp->next->next = NULL;
        }
    }
    void display()
    {
        cout << "Key         Value" << endl;
        for (int i = 0; i < s; i++)
        {
            if (table[i] != NULL)
            {
                cout << table[i]->key << "       " << table[i]->value << endl;
                node *t = new node;
                t = table[i];
                while (t->next != NULL)
                {
                    cout << t->next->key << "       " << t->next->value << endl;
                    t = t->next;
                }
            }
        }
    }

    void search(string k)
    {
        int index = hash_func(k);
        bool my = false;
        if (table[index] == NULL)
        {
            cout << "Not found!" << endl;
        }
        else
        {
            node *temp = new node;
            temp = table[index];
            while (temp != NULL)
            {
                if (temp->key == k)
                {
                    cout << k << "   :   " << temp->value << endl;
                    my = true;
                    break;
                }
                temp = temp->next;
            }
            if (!my)
            {
                cout << "Not found!" << endl;
            }
        }
    }
    void delet(string k)
    {
        
        int index = hash_func(k);
        node *par = NULL;
        node *t = table[index];
        if (t == NULL)
        {
            cout << "Entry doesn't exists!" << endl;
        }
        else if (t->key == k)
        {
            table[index] = table[index]->next;
            delete t;
        }
        else{
            while(t!=NULL && t->key!=k)
            {
                par=t;
                t=t->next;
            }
            if(t==NULL)
            {
                cout<<"Does not exists!"<<endl;
                return;
            }
            par->next=t->next;
            delete t;
        }
    }
};
int main()
{
    hash_table h;
    int oper;
    string a,b;
    do
    {
        cout<<"Enter:\n1:To insert an entry\n2:To delete an entry\n3:To display\n4:To search\n5:To exit\n---------->";
        cin>>oper;
        switch (oper)
        {
        case 1:
            cout<<"Enter key: ";
            cin>>a;
            cout<<"Enter value: ";
            cin>>b;
            h.insert(a,b);
            break;
        case 2:
            cout<<"Enter key to be deleted: ";
            cin>>a;
            h.delet(a);
            break;
        case 3:
            h.display();
            break;
        case 4:
            cout<<"Enter key to be search: ";
            cin>>a;
            h.search(a);
            break;
        default:
            break;
        }
    } while (oper!=5);
    

    return 0;
}
