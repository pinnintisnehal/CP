#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> arr;
vector<vector<int>>sparseTable;
void precompute_sparseTable(){
  int maxLen = log2(n) + 1;
  sparseTable.resize(maxLen, vector<int> (n+1));
  for(int i = 1; i <= n; i++){
    sparseTable[0][i] = arr[i];
  }
  for(int j = 1; j < maxLen; j++){
    for(int i = 1; i + (1 << j) - 1 <= n ; i++){
      sparseTable[j][i] = min(sparseTable[j - 1][i] , sparseTable[j - 1][i + (1 << j - 1)]);
    }
  }
}
int main(){
  int q;
  cin >> n >> q;
  arr.resize(n+1);
  for(int i = 1; i <= n; i++) cin >> arr[i];
  precompute_sparseTable();
  while(q--){
    int l , r;
    cin >> l >> r;
    int len = r - l + 1;
    int k = log2(len);
    int minEle = min(sparseTable[k][l] , sparseTable[k][r - (1 << k) +1]);
    cout << minEle ;
    cout << endl;
  }
}