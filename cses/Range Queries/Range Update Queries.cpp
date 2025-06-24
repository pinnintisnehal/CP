#include <bits/stdc++.h>
using namespace std;
#define ll long long

class ST {
    vector<ll> seg, lazy;

public:
    ST(ll n) {
        seg.resize(4 * n);
        lazy.resize(4 * n);
    }

    void build(ll ind, ll low, ll high, ll arr[]) {
        if (low == high) {
            seg[ind] = arr[low];
            return;
        }
        ll mid = (low + high) / 2;
        build(2 * ind + 1, low, mid, arr);
        build(2 * ind + 2, mid + 1, high, arr);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }

    void update(ll ind, ll low, ll high, ll val, ll l, ll r) {
        if (lazy[ind] != 0) {
            seg[ind] += (high - low + 1) * lazy[ind];
            if (low != high) {
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }
            lazy[ind] = 0;
        }

        if (high < l || r < low) return;

        if (low >= l && high <= r) {
            seg[ind] += (high - low + 1) * val;
            if (low != high) {
                lazy[2 * ind + 1] += val;
                lazy[2 * ind + 2] += val;
            }
            return;
        }

        ll mid = (low + high) / 2;
        update(2 * ind + 1, low, mid, val, l, r);
        update(2 * ind + 2, mid + 1, high, val, l, r);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }

    ll query(ll ind, ll low, ll high, ll k) {
        if (lazy[ind] != 0) {
            seg[ind] += (high - low + 1) * lazy[ind];
            if (low != high) {
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }
            lazy[ind] = 0;
        }

        if (low == high) return seg[ind];

        ll mid = (low + high) / 2;
        if (k <= mid)
            return query(2 * ind + 1, low, mid, k);
        else
            return query(2 * ind + 2, mid + 1, high, k);
    }
};

int main() {
    ll n, q;
    cin >> n >> q;
    ll arr[n];
    for (ll i = 0; i < n; i++) cin >> arr[i];

    ST st(n);
    st.build(0, 0, n - 1, arr);

    while (q--) {
        ll type;
        cin >> type;
        if (type == 1) {
            ll l, r, val;
            cin >> l >> r >> val;
            st.update(0, 0, n - 1, val, l - 1, r - 1);
        } else {
            ll k;
            cin >> k;
            cout << st.query(0, 0, n - 1, k - 1) << endl;
        }
    }
    return 0;
}
