/*3.	Write a program that reads an array of integer numbers from the user and sorts the numbers in the ascending order*/
#include <iostream>
using namespace std;

int main() 
{
    int n,temp;
    cout << "Enter number of elements: ";
    cin >> n;
    
    int a[n];
    cout << "Enter numbers: ";
    for (int i = 0; i < n; i++) 
	{
	cin >> a[i];
    }
    for (int i=0;i<n-1;i++)
    {
    	for(int j=i+1;j<n;j++)
    	{
    		if(a[i]<a[j])
    		{
    			temp=a[i];
    			a[i]=a[j];
    			a[j]=temp;
			}
		}
	}
	cout<<"\nAscending order =";
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<"\t";
	}
    return 0;
}

