#include <bits/stdc++.h>
using namespace std;
void dfs(int n,int m,int row,int col,vector<vector<char>>&mat,vector<vector<int>>&vis){
  vis[row][col]=1;
   int drow[]={-1,0,1,0};
   int dcol[]={0,1,0,-1};
  for(int i=0;i<4;i++){
    int nr=row+drow[i];
    int nc=col+dcol[i];
    if(nr>=0&&nr<n&&nc>=0&&nc<m&&mat[nr][nc]=='.'&&!vis[nr][nc]){
      dfs(n,m,nr,nc,mat,vis);
    }
  }
}
void solve(){
   int n,m;
   cin>>n>>m;
   vector<vector<char>>mat(n,vector<char>(m));
   for(int i=0;i<n;i++){
     for(int j=0;j<m;j++){
       cin>>mat[i][j];
     }
   }
   vector<vector<int>>vis(n,vector<int>(m,0));
   int cnt=0;
   for(int i=0;i<n;i++){
     for(int j=0;j<m;j++){
       if(mat[i][j]=='.'&&!vis[i][j]){
         dfs(n,m,i,j,mat,vis);
         cnt++;
       }
     }
   }
   cout<<cnt;
}
 
int main() {
 
        solve();
        cout << endl;
    return 0;
}
