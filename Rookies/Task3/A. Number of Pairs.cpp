#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,l,r;
        cin>>n>>l>>r;
        vector<int>v(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        long long cntr=0;
        for(int i=0;i<n;i++)
        {
            auto low =lower_bound(v.begin()+i+1,v.end(),l-v[i])-v.begin();
            auto high = upper_bound(v.begin() + i + 1, v.end(), r - v[i]) - v.begin() - 1;
            if(low<=high)
            {
                cntr+=high-low+1;
            }
        }
       cout<<cntr<<endl;
    }
    return 0;
}

