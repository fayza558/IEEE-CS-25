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
    int A=0,B=n-1;
    int cntrA=0,cntrB=0;
    int sumA=v[A],sumB=v[B];
    while(A<=B)
    {
        if(sumA<=sumB)
        {
            sumA+=v[++A];
            cntrA++;
        }else
        {
            sumB+=v[--B];
            cntrB++;
        }
    }
    cout<<cntrA<<" "<<cntrB<<endl;

    return 0;
}
