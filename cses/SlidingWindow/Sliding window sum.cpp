#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
  ll n , k;
  cin >> n >> k;
  vector<ll>arr(n);
  ll x, a, b, c;
  cin >> x >> a >> b >> c;
  arr[0] = x;
  for (int i = 1; i < n; i++) {
    arr[i] = (a * arr[i - 1] + b) % c;
  }
  for (auto &it : arr) cin >> it;
  ll sum = 0;
  ll xr = 0;
  for (int i = 0; i < k; i++) {
    sum += arr[i];
  }
  xr = xr ^ sum;
  for (int i = 1; i <= n - k; i++) {
    sum -= arr[i - 1];
    sum += arr[i + k - 1];
    xr = xr ^ sum;
  }
  cout << xr << endl;
}