#include <iostream>
#include<cmath>
#define ll long long
using namespace std;
ll  solve(int index,ll *arr,ll sum1,ll sum2,int n)
{
    if(index==n)
    {
        return abs(sum1-sum2);
    }
    ll choose =solve(index+1,arr,sum1+arr[index],sum2,n);
    ll notchoose=solve(index+1,arr,sum1,sum2+arr[index],n);
    return min(choose,notchoose);
}

int main()
{
    int n;
    cin>>n;
    ll arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    cout<<solve(0,arr,0,0,n)<<endl;


    return 0;
}
