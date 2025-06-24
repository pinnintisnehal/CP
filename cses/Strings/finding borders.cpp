#include<bits/stdc++.h>
using namespace std;
void computeLPS(string pat, int m, vector<int>&lps) {
    int i = 1, len = 0;
    while (i < m) {
        if (pat[i] == pat[len]) {
            lps[i] = len + 1;
            i++;
            len++;
        }
        else if (len != 0) {
            len = lps[len - 1];
        }
        else {
            lps[i] = 0;
            i++;
        }
    }
}
int main() {
    string pat;
    cin >> pat;
    int m = pat.size();
    vector<int>lps(m , 0);
    computeLPS(pat, m, lps);
    vector<int>match_len;
    int len = lps[m - 1];
    while (len > 0) {
        match_len.push_back(len);
        len = lps[len - 1];
    }
    reverse(match_len.begin() , match_len.end());
    for (auto it : match_len) {
        cout << it << " ";
    }
}