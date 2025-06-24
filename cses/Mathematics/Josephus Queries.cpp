#include<bits/stdc++.h>
using namespace std;
int solve(int n,int k){
  if(n==1){
    return 1;
  }
  int half=(n+1)/2;
  if(k<=half){
    if(2*k>n)return (2*k)%n;
    return 2*k;
  }
  int next=solve(n/2,k-half);
  if(n%2==0){
    return 2*next-1;
  }
  return 2*next+1;
}
int main(){
  int q;
  cin>>q;
  while(q--){
    int n,k;
    cin>>n>>k;
    int person=solve(n,k);
    cout<<person<<endl;
  }
}