#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
struct Node {
    Node*list[26];
    bool flag = false;
    bool containsKey(char ch) {
        return list[ch - 'a'] != nullptr;
    }
    void put(char ch, Node*node) {
        list[ch - 'a'] = node;
    }
    Node*get(char ch) {
        return list[ch - 'a'];
    }
    void setEnd() {
        flag = true;
    }
    bool getEnd() {
        return flag;
    }
};
class Trie {
public:
    Node*root;
public:
    Trie() {
        root = new Node();
    }
    void insert(string word) {
        Node*node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    bool search(string word) {
        Node*node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containsKey(word[i])) {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->getEnd();
    }
};
int main() {
    string str;
    cin >> str;
    int n;
    cin >> n;
    vector<string>v(n);
    vector<int>dp(str.length() + 1, 0);
    dp[0] = 1;
    Trie trie;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        v.push_back(s);
    }
    for (auto it : v) {
        trie.insert(it);
    }
    for (int i = 0; i < str.size(); i++) {
        if (!dp[i])continue;
        Node* node = trie.root;
        for (int j = i; j < str.size(); j++) {
            if (!node->containsKey(str[j])) break;
            node = node->get(str[j]);
            if (node->getEnd()) {
                dp[j + 1] = (dp[j + 1] + dp[i]) % MOD;
            }
        }
    }
    cout << dp[str.size()];
}