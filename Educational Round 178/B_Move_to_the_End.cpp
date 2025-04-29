#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#include <bits/stdc++.h>

using namespace std;

void solve () {
    int n;
    cin >> n;
    vector<pair<long long, int>> v(n);
    for(int i = 0; i < n ; i++) {
        int x;
        cin >> x;
        v[i] = make_pair(x, i);
    }
    sort(v.begin(), v.end());
    int j = n - 1;
    long long tmp = v[j].first;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}