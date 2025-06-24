#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define rll(x) x.rbegin(), x.rend()

const ll MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int max_n = 1e6 + 1;
vector<vector<int>> dp(max_n, vector<int>(2));
vector<int>res(max_n);
void precompute() {
    dp[0][0] = 1;
    dp[0][1] = 1;
    for (int i = 1; i < max_n; i++) {
        dp[i][0] = (2ll * dp[i - 1][0] + dp[i - 1][1]) % MOD;
        dp[i][1] = (4ll * dp[i - 1][1] + dp[i - 1][0]) % MOD;
        res[i] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
    }

}

int main() {
    precompute();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << res[n] << endl;
    }
    return 0;
}
