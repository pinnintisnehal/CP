#include<bits/stdc++.h>
using namespace std;
#define int long long
class Find_median {
    multiset<int>low , high;
public:
    void balance() {
        while (low.size()  > high.size() + 1) {
            high.insert(*low.rbegin());
            low.erase(prev(low.end()));
        }
        while (high.size() > low.size()) {
            low.insert(*high.begin());
            high.erase(high.find(*high.begin()));
        }
    }
public:
    void insert(int num) {
        if (low.size() == 0 ||  *low.rbegin() > num) {
            low.insert(num);
        }
        else {
            high.insert(num);
        }
        balance();
    }
public:
    void erase(int num) {
        if (low.find(num) != low.end()) {
            low.erase(low.find(num));
        }
        else {
            high.erase(high.find(num));
        }
        balance();
    }
public:
    int get_median() {
        return *low.rbegin();
    }
};


signed main() {
    Find_median fm;
    int n , k;
    cin >> n >> k;
    vector<int>arr(n);
    for (auto &it : arr) cin >> it;
    vector<int>ans;
    for (int i = 0; i < k; i++) {
        fm.insert(arr[i]);
    }
    ans.push_back(fm.get_median());
    for (int i = k; i < n; i++) {
        fm.erase(arr[i - k]);
        fm.insert(arr[i]);
        ans.push_back(fm.get_median());
    }
    for (auto it : ans) cout << it << " ";
    cout << endl;
}