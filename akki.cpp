#include <iostream>
using namespace std;

int main() {
	int tc,n,k,i,x;
	cin>>tc;
	while(tc--)
	{
	    cin>>n>>k;
		int a[n];
	    for(i=0;i<n;i++)
	    {
	        cin>>a[i];
	        if(a[i]<k)
	        {
	            k=k-a[i];
	            cout<<"1";
	        }
	        else
	        {
	            cout<<"0";
	        }
	    }
	}
	return 0;
}

