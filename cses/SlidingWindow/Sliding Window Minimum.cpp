#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ll n, k;
  cin >> n >> k;
  vector<ll> arr(n);
  ll x, a, b, c;
  cin >> x >> a >> b >> c;
  arr[0] = x;
  for (int i = 1; i < n; i++) {
    arr[i] = (a * arr[i - 1] + b) % c;
  }
  ll xr = 0;
  deque<int>dq;
  vector<int>ans;
  for (int i = 0; i < n; i++) {
    while (!dq.empty() && arr[dq.back()] >= arr[i]) dq.pop_back();
    dq.push_back(i);
    if (dq.front() <= i - k) dq.pop_front();
    if (i >= k - 1) {
      xr = xr ^ arr[dq.front()];
    }
  }
  cout << xr << endl;
  return 0;
}
