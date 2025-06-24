#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define rll(x) x.rbegin(), x.rend()

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}
int f(int i, int j, int m, int n, string s, string p, vector<vector<int>>&dp) {
  if (i < 0) return j + 1;
  if (j < 0) return i + 1;
  if (s[i] == p[j]) {
    return f(i - 1, j - 1, m, n, s, p, dp);
  }
  if (dp[i][j] != -1)return dp[i][j];
  int ins = 1 + f(i, j - 1, m, n, s, p, dp);
  int del = 1 + f(i - 1, j, m, n, s, p, dp);
  int rep = 1 + f(i - 1, j - 1, m, n, s, p, dp);
  return dp[i][j] = min(ins, min(del, rep));
}
int solve() {
  string s, p;
  cin >> s >> p;
  int m = s.size(), n = p.size();
  vector<vector<int>>dp(m + 1, vector<int>(n + 1, 0));

  for (int i = 0; i <= m; i++) {
    dp[i][0] = i;
  }
  for (int i = 0; i <= n; i++) {
    dp[0][i] = i;
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (s[i - 1] == p[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1];
      }
      else {
        dp[i][j] = 1 + min( dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j]));
      }
    }
  }
  return dp[m][n];
}

int main() {
  cout << solve();
  return 0;
}
