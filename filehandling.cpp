#include <iostream>
#include <fstream>
using namespace std;

class student
{
public:
    char name[10];
    int roll;
    void getdata();
    void putdata();
};

void student::getdata()
{
    cout << "\nEnter roll no: ";
    cin >> roll;
    cout << "\nEnter name: ";
    cin >> name;
}
void student::putdata()
{
    cout << "\nRoll No: " << roll << "\nName: " << name;
}

class file
{
    fstream fp;

public:
    void create();
    void append();
    void display();
    void delete1();
};

void file::create()
{
    char ans;
    student s;
    fp.open("stu.txt", ios::out);
    do
    {
        s.getdata();
        fp.write((char *)&s, sizeof(s));
        cout << "\nDo you want to add more data(y/n or 1/0)?";
        cin >> ans;
    } while (ans == 'Y' || ans == 'y' || ans == '1');
    fp.close();
}

void file::append()
{
    char ans;
    student s;
    fp.open("stu.txt", ios::app);
    do
    {
        s.getdata();
        fp.write((char *)&s, sizeof(s));
        cout << "\nDo you want to add more data(y/n or 1/0)?:";
        cin >> ans;
    } while (ans == 'Y' || ans == 'y' || ans == '1');
    fp.close();
}

void file::display()
{
    student s;
    fp.open("stu.txt", ios::in);
    while (!fp.eof())
    {
        fp.read((char *)&s, sizeof(s));
        if (!fp.eof())
            s.putdata();
    }
    fp.close();
}

void file::delete1()
{
    student s;
    int flag = 0;
    fstream fp1;
    cout << "\n Enter roll to be deleted:";
    int r;
    cin >> r;
    fp.open("stu.txt", ios::in);
    fp1.open("temp.txt", ios::out);
    while (fp.read((char *)&s, sizeof(s)))
    {
        if (s.roll != r)
        {
            flag = 1;
            fp1.write((char *)&s, sizeof(s));
        }
    }
    if (flag == 0)
        cout << "\n Not found";
    fp.close();
    fp1.close();
    remove("stu.txt");
    rename("temp.txt", "stu.txt");
}

int main()
{
    file f;
    int choice;
    do
    {
        cout << "\n1. Create \n2. Display \n3. Append"
                "\n4. Delete \n5. Exit "
                "\nEnter choice:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            f.create();
            break;
        case 2:
            f.display();
            cout<<"\n";
            break;
        case 3:
            f.append();
            break;
        case 4:
            f.delete1();
            cout<<"\nData deleted.\n";
            break;
        case 5:
            return 0;
        default:
            cout << "\n!!Wrong Choice!!";
            break;
        }
    } while (choice < 8);
    return 0;
}