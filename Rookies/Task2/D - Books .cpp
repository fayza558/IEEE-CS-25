#include <iostream>
#include<vector>
#define ll long long
using namespace std;
const ll N=2e5+5;
ll n,k;
vector<int>pref(N,0);
bool isOk(ll mid)
{
    ll l=1,r=mid;
    while(r<=n)
    {
        if(pref[r]-pref[l-1]<=k) return true;
         l++,r++;
    }
    return false;
}

int main()
{
    cin>>n>>k;
    int arr[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>pref[i];
        pref[i]+=pref[i-1];
    }
    ll  l =0,r=n,mid,ans=-1;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(isOk(mid))
        {
            l=mid+1;
            ans=mid;
        }else
        {
            r=mid-1;
        }
    }
    cout<<ans<<endl;

    return 0;
}
