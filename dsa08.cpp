#include <bits/stdc++.h>
using namespace std;

#define MAX 100

class Node
{
    int name;
    Node *next;

public:
    friend class Graph;
    Node(int s)
    {
        name = s;
        next = NULL;
    }
};

class stacks
{
    int top;
    Node *s[MAX];

public:
    stacks()
    {
        top = -1;
    }
    int isFull()
    {
        if (top == MAX -1)
            return 1;
        else
            return 0;
    }
    int isEmpty()
    {
        if (top == -1)
            return 1;
        else
            return 0;
    }
    void push(Node *p)
    {
        if (isFull())
        {
            cout << "\nStack is Full";
        }
        else
        {
            top++;
            s[top] = p;
        }
    }
    Node *pop()
    {
        Node *p;
        if (isEmpty())
        {
            cout << "\nStack is Empty";
        }
        else
        {
            p = s[top];
            top--;
        }
        return p;
    }
};

class Queue
{
    int front ,rear;
    Node* q[MAX];
    public:
    Queue()
    {
        front = rear = -1;
    }
    int is_Full()
    {
        if(rear == MAX -1) return 1;
        else return 0;
    }
    int is_Empty()
    {
        if(front > rear || rear == -1) return 1;
        else return 0;
    }
    void enqueue(Node*p)
    {
        if(is_Full())
        {
            cout<<"\nQueue is Full";
        }
        else if(is_Empty())
        {
            front = 0; rear = 0; q[rear] = p;
        }
        else
        {
            rear++; q[rear] = p;
        }
    }
    Node *dequeue()
    {
        Node*p;
        if(is_Empty())
        {
            cout<<"\nQueue is Empty";
        }
        else
        {
            p = q[front];
            front++;
        }
        return p;
    }
};

class Graph
{
    int no_vertices, no_edges;
    Node **header;

public:
    Graph(int v, int e)
    {
        no_vertices = v;
        no_edges = e;
        header = new Node *[no_vertices];
        for (int i = 0; i < no_vertices; i++)
        {
            header[i] = new Node(i);
        }
    }

    void accept_graph()
    {
        int s, d;
        int index = 0;
        while (no_edges--)
        {
            cout << "\n";
            cout << "Enter source city: ";
            cin >> s;
            cout << "Enter destination city: ";
            cin >> d;
            Node *temp = header[s];
            Node *dest = new Node(d);
            if (header[s] == NULL)
            {
                header[s] = dest;
            }
            else
            {
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = dest;
            }
        }
    }

    void display_graph()
    {
        cout << "\nDISPLAY\n";
        for (int i = 0; i < no_vertices; i++)
        {
            Node *temp = header[i];
            cout <<"City "<<temp->name << " ---> [ ";
            temp = temp->next;
            while (temp != NULL)
            {
                cout <<"City "<<temp->name << " -> ";
                temp = temp->next;
            }
            cout << "# ] ";
            cout << "\n";
        }
    }

    void indegree_calculation()
	{
        for(int i=0;i<n;i++)
		{
            visited[i] = 0; 
		indegree[i] = 0;
		for(j=o;j<n;j++)
			if(G[j][i]!=0)
				indegree[i] = indegree[i] + 1;
			endif
		endfor
		if(indegree[i] ==0)
			q.add(i);
        }
    }

};

int main()
{
    cout << "\n\nACCEPTING GRAPH\n\n";
    int v, e;
    cout << "Enter no. of vertices (cities) :";
    cin >> v;
    cout << "Enter no. of edges (routes) :";
    cin >> e;
    Graph g(v, e);
    g.accept_graph();
    int var = 1;
    int start;
    while (var == 1)
    {
        int choice;
        cout << "\n\n--------------MENU--------------\n\n";
        cout << "Enter your choice : \n";
        cout << " 1)Display Graph \n 2)BFS \n 3)DFS\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            g.display_graph();
            break;
        }
        case 2:
        {
            g.BFS();
            cout<<"\n";
            break;
        }
        case 3:
        {
            g.DFS();
            cout<<"\n";
            break;
        }
        default:
        {
            cout << "Enter valid choice !";
            break;
        }
        }
        cout << "\nDo you want to continue (0/1) : ";
        cin >> var;
    }
}

