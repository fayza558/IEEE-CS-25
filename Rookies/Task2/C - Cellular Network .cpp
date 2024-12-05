#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>v(n);
    vector<int>k(m);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
     for(int i=0;i<m;i++)
    {
        cin>>k[i];
    }
    sort(v.begin(),v.end());
    sort(k.begin(),k.end());
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int p=lower_bound(k.begin(),k.end(),v[i])-k.begin();
        if(p==0)
        {
        ans=max(ans,abs(v[i]-k[p]));
        }else if(p==m)
        {
            ans=max(ans,abs(v[i]-k[p-1]));
        }else
        {
            ans=max(ans,min(abs(v[i]-k[p]),abs(v[i]-k[p-1])));
        }
    }
    cout<<ans<<endl;
    return 0;
}
