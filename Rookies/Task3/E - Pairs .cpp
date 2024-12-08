#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int k,n;
    cin>>n>>k;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int l=0,r=1;
    int cntr=0;
    while(r<n)
    {
        int diff=v[r]-v[l];
        if(diff==k)
        {
            cntr++;
            l++;
            r++;
        }else if(diff<k)
        {
            r++;
        }else
        {
            l++;
        }
        if(l==r)
        {
            r++;
        }
    }
    cout<<cntr<<endl;
    return 0;
}
