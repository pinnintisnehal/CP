#include<bits/stdc++.h>
using namespace std;
#define ll long long

class ST {
    vector<ll>seg;
public:
    ST(ll n) {
        seg.resize(4 * n);
    }
public:
    void build(ll ind , ll low , ll high , ll arr[]) {
        if (low == high) {
            seg[ind] = arr[low];
            return;
        }
        ll mid = (low + high) >> 1;
        build(2 * ind + 1 , low , mid , arr);
        build(2 * ind + 2 , mid + 1 , high , arr);
        seg[ind] = min(seg[2 * ind + 1] , seg[2 * ind + 2]);
    }
public:
    void update(ll ind , ll  low , ll high , ll k , ll u) {
        if (low == high) {
            seg[ind] = u;
            return;
        }
        ll mid = (low + high) >> 1;
        if (k <= mid) {
            update(2 * ind + 1 , low , mid , k , u);
        }
        else update(2 * ind + 2 , mid + 1 , high , k , u);
        seg[ind] = min(seg[2 * ind + 1] , seg[2 * ind + 2]);
    }
public:
    ll query(ll ind , ll low , ll high , ll l , ll r) {
        if (high < l || r < low) return INT_MAX;
        if (low >= l && high <= r) return seg[ind];
        ll mid = (low + high) >> 1;
        ll left = query(2 * ind + 1 , low , mid , l , r);
        ll right = query(2 * ind + 2 , mid + 1 , high , l , r);
        return min(left , right);
    }
};

int main() {
    ll n , q;
    cin >> n >> q;
    ll arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    ST st(n);
    st.build(0 , 0 , n - 1 , arr);
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            ll k , u;
            cin >> k >> u;
            k--;
            st.update(0 , 0 , n - 1 , k , u);
        }
        else {
            ll l , r;
            cin >> l >> r;
            l--;
            r--;
            cout << st.query(0 , 0 , n - 1 , l , r) << endl;
        }
    }
}