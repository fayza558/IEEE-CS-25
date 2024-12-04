#include <iostream>
#include<algorithm>
#include<vector>
#define ll long long

using namespace std;

int main()
{
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(int i=0; i<n; i++)
    {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int q;
    cin>>q;
    while(q--)
    {
        ll l=0,r=n-1;
        ll mid;
        ll ans=-1;
        ll index=0;
        int x;
        cin>>x;
        while(l<=r)
        {
            mid =(l+r)/2;
            if(v[mid]<=x)
            {
                ans=mid;
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        cout<<ans+1<<endl;

    }
    return 0;
}


