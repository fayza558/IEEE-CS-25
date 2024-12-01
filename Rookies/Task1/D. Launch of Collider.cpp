#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int ans=1e9;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='R'&&s[i+1]=='L')
        {
            ans=min(ans,(arr[i+1]-arr[i])/2);
        }
    }
    if(ans==1e9)
    {
        cout<<-1<<endl;
    }else
    {
        cout<<ans<<endl;
    }
    return 0;
}
