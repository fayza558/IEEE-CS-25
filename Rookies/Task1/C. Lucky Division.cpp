#include <iostream>

using namespace std;
isLucky(int num)
{
    string s=to_string(num);
    for(char c:s)
    {
        if(c!='4'&&c!='7')
        {
            return false ;
        }
    }
    return true;
}
bool Lucky(int n)
{
    for(int i=1;i<=n;i++)
    {
        if(isLucky(i)&&n%i==0)
        {
            return true;
        }
    }
    return false ;
}
int main()
{
    int n;
    cin>>n;
    if(Lucky(n))
    {
        cout<<"YES"<<endl;
    }else
    {
        cout<<"NO"<<endl;
    }

    return 0;
}
//fayza
