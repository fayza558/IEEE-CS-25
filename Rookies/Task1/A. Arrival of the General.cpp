#include <iostream>
#include<vector>
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
    int minnHeight=v[0];
    int maxHeight=v[0];
    int posMinn=0,posMaxx=0;
    for(int i=1;i<n;i++)
    {
       if(v[i]>maxHeight)
       {
           maxHeight=v[i];
           posMaxx=i;
       }
       if(v[i]<=minnHeight)
       {
           minnHeight=v[i];
           posMinn=i;
       }
    }
    int ans=(posMaxx-0)+(n-1-posMinn);
    if(posMaxx>posMinn)
    {
        ans--;
    }
    cout<<ans<<endl;

    return 0;
}
