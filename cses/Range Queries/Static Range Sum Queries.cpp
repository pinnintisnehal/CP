#include<bits/stdc++.h>
using namespace std;
int main(){
  long long n,q;
  cin>>n>>q;
  vector<long long>arr(n+1);
  vector<long long>pref(n+1);
  pref[0]=0;
  for(int i=1;i<=n;i++){
    cin>>arr[i];
    pref[i]=pref[i-1]+arr[i];
  }
  while(q--){
    long long l,r;
    cin>>l>>r;
    long long sum=pref[r]-pref[l-1];
    cout<<sum<<endl;
  }
}