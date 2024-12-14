#include <iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
void solve(string& str,int index,set<string>&permutation)
{
    if(index==str.size())
    {
        permutation.insert(str);
        return ;
    }
    for(int i=index;i<str.size();i++)
    {
        swap(str[index],str[i]);
        solve(str,index+1,permutation);
        swap(str[index],str[i]);
    }
}

int main()
{
    string s;
    cin>>s;
    set<string>permutation;
    solve(s,0,permutation);
    cout<<permutation.size()<<endl;
    for(const string& perm:permutation)
    {
        cout<<perm<<endl;
    }
    return 0;
}
