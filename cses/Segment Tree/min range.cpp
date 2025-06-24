#include<bits/stdc++.h>
using namespace std;
class ST {
	vector<int>seg;
public:
	ST(int n) {
		seg.resize(4 * n);
	}
public:
	void build(int ind , int low , int high , int arr[] , int order) {
		if (low == high) {
			seg[ind] = arr[low];
			return;
		}
		int mid = (low + high) >> 1;
		build(2 * ind + 1 , low , mid , arr , !order);
		build(2 * ind + 2, mid + 1 , high , arr , !order);
		if (order) {
			seg[ind] = (seg[2 * ind + 1] | seg[2 * ind + 2]);
		}
		else seg[ind] = (seg[2 * ind + 1] ^ seg[2 * ind + 2]);
	}
public:
	int query(int ind , int low , int  high , int l , int r , int order) {
		//no overlap
		if (high < l || r < low) return 0;
		// complete overlap
		if (low >= l && high <= r) {
			return seg[ind];
		}
		// partial overlap
		int mid = (low + high) >> 1;
		int left = query(2 * ind + 1 , low , mid , l , r , !order);
		int right = query(2 * ind + 2 , mid + 1 , high , l , r , !order);
		if (order) return (left | right);
		else return left ^ right;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n , q;
	cin >> n >> q;
	int arr[n];
	for (int i = 0; i < n; i++) cin >> arr[i];
	ST st(n);
	if (n % 2) st.build(0 , 0 , n - 1 , arr , 1);
	else st.build(0 , 0 , n - 1 , arr , 0);
	while (q--) {
		int l , r;
		cin >> l >> r;
		l--, r--;
		cout << st.query(0 , 0 , n - 1 , l , r  , n % 2) << endl;
	}
}