#include <iostream>
#include<vector>
#define ll long long
using namespace std;

int main()
{
  int n,d;
  cin>>n>>d;
  vector<ll>v(n);
  for(int i=0;i<n;i++)
  {
      cin>>v[i];
  }
  ll cntr=0;
  for(int i=0;i<n;i++)
  {
      ll l=i,r=n-1;
      ll maxx=i;

      while(l<=r)
      {
          ll mid =(l+r)/2;
          if(v[mid]-v[i]<=d)
          {
              maxx=mid;
              l=mid+1;
          }else{
              r=mid-1;
          }
      }
      ll len=maxx-i;
      if(len>=2)
      {
          cntr+=(len*(len-1))/2;
      }
  }
  cout<<cntr<<endl;
    return 0;
}
