#include<bits/stdc++.h>
using namespace std;
int MOD1 = 1e9 + 7;
int MOD2 = 1e9 + 33;
int base1 = 26, base2 = 27;
 
pair<long long, long long> find_hash(string pat, int m) {
  long long sum1 = 0, sum2 = 0, prod1 = 1, prod2 = 1;
  for (int i = m - 1; i >= 0; i--) {
    sum1 += ((pat[i] - 'a') * prod1) % MOD1;
    prod1 = (prod1 * base1) % MOD1;
    sum2 += ((pat[i] - 'a') * prod2) % MOD2;
    prod2 = (prod2 * base2) % MOD2;
  }
  return {sum1 % MOD1, sum2 % MOD2};
}
int main() {
  string txt, pat;
  cin >> txt >> pat;
  int n = txt.size();
  int m = pat.size();
  long long max_base1 = 1, max_base2 = 1;
  for (int i = 0; i < m; i++) {
    max_base1 = (max_base1 * base1) % MOD1;
    max_base2 = (max_base2 * base2) % MOD2;
  }
  pair<long long, long long>p1 = find_hash(txt , m);
  pair<long long, long long>p2 = find_hash(pat, m);
  int occurance_cnt = 0;
  for (int i = 0; i <= n - m; i++) {
    if (i > 0) {
      p1.first = ((p1.first * base1) % MOD1 - (max_base1 * (txt[i - 1] - 'a')) % MOD1 + txt[i + m - 1] - 'a' + MOD1 ) % MOD1;
      p1.second = ((p1.second * base2) % MOD2 - (max_base2 * (txt[i - 1] - 'a')) % MOD2 + txt[i + m - 1] - 'a' + MOD2 ) % MOD2;
    }
    if (p1.first == p2.first && p1.second == p2.second) {
      occurance_cnt++;
    }
  }
  cout << occurance_cnt ;
}
