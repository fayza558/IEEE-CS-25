#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    int police=0;
    int crime=0;
    for(int i=0; i<n; i++)
    {
        if(arr[i]==-1)
        {
            if(police>0)
            {
                police--;
            }
            else
            {
                crime++;
            }
        }
        else
        {
            police+=arr[i];
        }
    }
    cout<<crime<<endl;
    return 0;
}
