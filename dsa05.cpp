#include <iostream>
using namespace std;
#define size 9

class hashEntry
{
    string word, meaning;
    hashEntry *next;

public:
    friend class hashTable;
    hashEntry()
    {
        word = "";
        meaning = "";
        next = NULL;
    }
    hashEntry(string w, string m)
    {
        word = w;
        meaning = m;
        next = NULL;
    }
};
class hashTable
{
    hashEntry *ht[size];

public:
    hashTable()
    {
        for (int i = 0; i < size; i++)
        {
            ht[i] = NULL;
        }
    }
    int hashFunction(string s)
    {
        int sum = 0;
        for (int i = 0; i < s.length(); i++)
        {
            sum = sum + s[i]*i;
        }
        return (sum % size);
    }
    void insert()
    {
        int var = 1;
        int flag = 0;
        while (var == 1)
        {
            string x, y;
            cout << "\nEnter word :";
            cin >> x;
            cout << "Enter meaning :";
            cin >> y;
            int hash_index = hashFunction(x);
            hashEntry *temp = ht[hash_index];
            if (ht[hash_index] == NULL)
            {
                temp = new hashEntry(x, y);
                ht[hash_index] = temp;
                cout << "Word inserted successfully";
            }
            else if (temp->word == x)
            {
                cout << "Word already exists";
            }
            else
            {
                while (temp->next != NULL)
                {
                    temp = temp->next;
                    if (temp->word == x)
                    {
                        cout << "Word already exists";
                        flag = 1;
                        break;
                    }
                }
                temp->next = new hashEntry(x, y);
                cout << "Word inserted successfully";
            }
            cout << "\nDo you want to continue adding more words  (0/1):";
            cin >> var;
        }
    }
    void display()
    {
        cout << "\nIndex\n";
        for (int i = 0; i < size; i++)
        {
            if (ht[i] == NULL)
            {
                cout << i << endl;
            }
            else
            {
                cout << i << " -->>";
                hashEntry *temp = ht[i];
                while (temp != NULL)
                {
                    cout << temp->word << "=" << temp->meaning << "--->>";
                    temp = temp->next;
                }
                cout << "NULL";
                cout << "\n";
            }
        }
    }
    void search()
    {
        int comp = 0;
        string s;
        cout << "\nEnter word :";
        cin >> s;
        int hash_index = hashFunction(s);
        hashEntry *temp = ht[hash_index];
        while (1)
        {
            if (temp == NULL)
            {
                cout << "Word not found\n";
                break;
            }
            else if (temp->word == s)
            {
                comp++;
                cout << "Word found at index :" << hash_index << "\n";
                cout << "Number of comparisions are: " << comp << "\n";
                break;
            }
            else
            {
                temp = temp->next;
                comp++;
            }
        }
    }
    void delete1()
    {
        string s;
        cout << "Enter word to be deleted:";
        cin >> s;
        int hash_index = hashFunction(s);
        if (ht[hash_index] == NULL)
        {
            cout << "Word not found";
        }
        else
        {
            hashEntry *temp = ht[hash_index];
            hashEntry *toDelete;
            if (temp->word == s)
            {
                toDelete = temp;
                ht[hash_index] = temp->next;
                delete toDelete;
                cout << "Successfully Deleted!!";
            }
            else
            {
                while (temp->next->word != s)
                {
                    temp = temp->next;
                }
                toDelete = temp->next;
                delete toDelete;
                cout << "Successfully Deleted!!";
            }
        }
    }
};

int main()
{
    hashTable h1;
    int var = 1;
    int a;
    while (var == 1)
    {
        cout << "\tMENU \n1)Insert\n2)Display\n3)Search\n4)Delete\n";
        cout<<"\nEnter your choice: ";
        cin >> a;
        switch (a)
        {
        case 1:
        {
            h1.insert();
            break;
        }
        case 2:
        {
            h1.display();
            break;
        }
        case 3:
        {
            h1.search();
            break;
        }
        case 4:
        {
            h1.delete1();
            break;
        }
        }
        cout << "\nDo you want to continue(0/1):";
        cin >> var;
    }
}
