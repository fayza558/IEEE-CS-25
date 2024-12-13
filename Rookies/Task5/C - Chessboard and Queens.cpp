#include <iostream>
#include<vector>
using namespace std;

void solve (vector <string>&board,int row,vector<bool>&occupiedCol,vector<bool>&occupiedPrimary,vector<bool>&occupiedSecondary,int &ans)
{
   if(row==8)
   {
       ans+=1;
       return ;
   }
   for(int col=0;col<8;col++)
   {
       if(board[col][row]=='*'||occupiedCol[col]||occupiedPrimary[row-col+8]||occupiedSecondary[row+col])
       {
           continue;
       }

        occupiedCol[col] = occupiedPrimary[row - col + 8] = occupiedSecondary[row + col] = true;
        solve(board, row + 1, occupiedCol, occupiedPrimary, occupiedSecondary, ans);
        occupiedCol[col] = occupiedPrimary[row - col + 8] = occupiedSecondary[row + col] = false;
   }
}


int main()
{
    vector<string>board(8);
    for(int i=0;i<8;i++)
    {
       cin>>board[i];
    }
    vector<bool> occupiedCol(8, false);
    vector<bool> occupiedPrimary(16, false);
    vector<bool> occupiedSecondary(16, false);
    int ans=0;
    solve(board,0,occupiedCol,occupiedPrimary,occupiedSecondary,ans);
    cout<<ans<<endl;

    return 0;
}
