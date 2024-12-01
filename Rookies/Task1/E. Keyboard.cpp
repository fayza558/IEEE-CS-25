#include <iostream>

using namespace std;

int main()
{
    char c;
    cin>>c;
    string keyboard="qwertyuiopasdfghjkl;zxcvbnm,./";
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
       for(int j=0;j<keyboard.size();j++)
       {
           if(s[i]==keyboard[j])
           {
               if(c=='R')
               {
                   s[i]=keyboard[j-1];
               }else if(c=='L')
               {
                   s[i]=keyboard[j+1];
               }
               break;
           }
       }
    }
    cout<<s<<endl;
    return 0;
}
