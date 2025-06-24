#include<bits/stdc++.h>
using namespace std;
int dfs(int u,vector<vector<int>>&adj,vector<int>&subOrdinate){
  int cnt=0;
  for(auto v:adj[u]){
    cnt+=1+dfs(v,adj,subOrdinate);
  }
  subOrdinate[u]=cnt;
  return cnt;
}
int main(){
  int n;
  cin>>n;
  vector<vector<int>>adj(n+1);
  vector<int>subOrdinate(n+1);
  for(int i=2;i<=n;i++){
    int boss;
    cin>>boss;
    adj[boss].push_back(i);
  }
  dfs(1,adj,subOrdinate);
  for(int i=1;i<=n;i++){
    cout<<subOrdinate[i]<<" ";
  }
  cout<<endl;
}