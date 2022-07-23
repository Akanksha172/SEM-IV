#include <iostream>
using namespace std;
#define MAX 100

class heap
{
    int arr[MAX];

public:
    heap()
    {
        for(int i=0;i<MAX;i++)
        {
            arr[i]=0;
        }
    }

    void insert()
    {
        int x;
        cout<<"Enter the element to be inserted : ";
        cin>>x;
        int temp,y;
        for(int i=1;i<MAX;i++)
        {
            if(arr[i]==0)
            {
                arr[i]=x;
                temp=arr[i];
                y=i;
                break;
            }
        }
        while(y>1 && arr[y] > arr[y/2])
        {
            arr[y]=arr[y/2];
            arr[y/2]=temp;
            y=y/2;
        }
    }

    void display(int n)
    {
        for(int i=1;i<=n;i++)
        {
            cout<<arr[i]<<" ";
        }
    }

    void arrange(int a)
    {
        int del,temp;
        del=arr[1];
        arr[1]=arr[a];
        arr[a]=del;

        int i=1,j=2*i;

        while(1)
        {
            a--;
            if(a==1)
            {
                break;
            }
            if(a>2)
            {
                if(arr[j]<arr[j+1] && j<=a)
                {
                    j=j+1;
                }
            }
            if(arr[i]<arr[j] && j<=a)
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
                i=j;
                j=2*j;
            }
            else
            {
                break;
            }
        }
    }

    void sort(int a)
    {
        for(int i=a;i>1;i--)
        {
            arrange(i);
        }
        for(int i=1;i<=a;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

};

int main()
{
    heap h;
    int n;
    cout<<"Enter the no. of elements in the heap : ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        h.insert();
    }
    int choice;

    do
    {
        cout<<"MENU : "<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;

        switch(choice)
        {
            case 1: 
                h.display(n);
                break;
            
            case 2:
                h.sort(n);
                break;

            default:
                cout<<"Please enter a valid choice !"<<endl;
                break;
        }
        cout<<"Do you want to continue ?";
        cin>>choice;
    } while (choice != 0);
    return 0;
}