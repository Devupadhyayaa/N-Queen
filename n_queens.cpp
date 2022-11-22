#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define tc ll t; cin>>t;while(t--)
#define loop(variable,n) for(int variable=0;variable<n;variable++)
void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
bool valid(int col,int row,vector<string>&board,int n){
    int dc=col;
    int dr=row;
    while(col>=0&&row>=0){
        if(board[row][col]=='Q'){
            return false;
        }
        row--;
        col--;
    }
    col=dc;row=dr;
    while(col>=0){
        if(board[row][col]=='Q'){
            return false;
        }
        col--;
    }
    col=dc,row=dr;
    while(row<n&&col>=0){
        if(board[row][col]=='Q'){
            return false;
        }
        col--;row++;
    }
    return true;
}
void solve(int col,vector<vector<string>>&ans,vector<string>&board,int n){
    if(col==n){
        ans.push_back(board);
        return;
    }
    for(int row=0;row<n;row++){
        if(valid(col,row,board,n)){
            board[row][col]='Q';
            solve(col+1,ans,board,n);
            board[row][col]='.';
        }
    }
}
vector<vector<string>> solveNQueens(int n){
    vector<vector<string>>ans;
    vector<string>board(n);
    string str(n,'.');
    loop(i,n){
        board[i]=str;
    }
    solve(0,ans,board,n);
    return ans;
}
int main(){
    fastIO();
    int n;cin>>n;
    vector<vector<string>>v=solveNQueens(n);
    loop(i,n){
        loop(j,n){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
return 0;
}
/*
1. Wrong Ans?
Did u read the Statement properly?
Did u miss any constraints?
Did u miss any corner case?
Are u sure about your Solution?
2. No Idea?
Try Greedy..
Try DP...
First Try Recursive DP..
Then Try Iterative DP..
If memory exceeds, then try to reduce it..
If not possible then, try to solve it using following way..
Try to solve it using Permutation ans Combination..
Try to find Sequence..
Try to Solve it using Algebra..
*/