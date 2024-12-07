#include <iostream>
#include<vector>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    int ans=0;
    int l=0,r=0,sum=0;
    while(r<n)
    {
        while(r<n&&(v[r]+sum)<=k)
        {
            sum+=v[r];
            r++;
        }
        ans=max(ans,r-l);
        sum-=v[l];
        l++;
    }
    cout<<ans<<endl;
    return 0;
}
