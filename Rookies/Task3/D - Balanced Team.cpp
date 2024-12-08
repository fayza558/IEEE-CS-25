#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int minn=v[0],ans=0;
    int l=0,r=0;
    while(r<n)
    {
        while(r<n&&v[r]-minn<=5)
        {
            r++;
        }
        ans=max(ans,r-l);
        l++;
        minn=v[l];
    }
    cout<<ans<<endl;
    return 0;
}
