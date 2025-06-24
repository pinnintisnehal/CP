#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ll n, k;
  cin >> n >> k;
  vector<ll> arr(n);
  for (auto &it : arr) cin >> it;
  ll l = 0 , r = 0;
  map<int , int>mpp;
  vector<ll>ans;
  while (r < n) {
    mpp[arr[r]]++;
    if (r - l + 1 == k) {
      ans.push_back(mpp.size());
      mpp[arr[l]]--;
      if (mpp[arr[l]] == 0) mpp.erase(arr[l]);
      l++;
    }
    r++;
  }
  for (auto it : ans) cout << it << " ";
}
