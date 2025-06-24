#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
  int n, k;
  cin >> n >> k;
  vector<int> arr(n);
  for (auto &it : arr) cin >> it;
  vector<int> ans;
  map<int , int>mpp;
  set<int>st;
  for (int i = 0; i <= n; i++) {
    st.insert(i);
  }
  for (int i = 0; i < k; i++) {
    mpp[arr[i]]++;
    if (st.find(arr[i]) != st.end()) {
      st.erase(arr[i]);
    }
  }
  ans.push_back(*st.begin());
  for (int i = k; i < n; i++) {
    mpp[arr[i - k]]--;
    if ( mpp[arr[i - k]] == 0) st.insert(arr[i - k]);
    mpp[arr[i]]++;
    if (st.find(arr[i]) != st.end()) st.erase(arr[i]);
    ans.push_back(*st.begin());
  }
  for (auto it : ans) cout << it << " ";
  cout << endl;
}
