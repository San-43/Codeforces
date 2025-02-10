#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<long long int> a(n);
    vector<long long int> b(m);
    for (auto &it : a) {
        cin >> it;
    }
    for (auto &it : b) {
        cin >> it;
    }

    ranges::sort(b);

    long long  int value = LLONG_MIN;
    long long int infinity = LLONG_MAX;

    for (int i = 0; i < n; i++) {
        auto it = ranges::lower_bound(b, value + a[i]);
        long long val = 0;

        if (it == end(b)) {
            val = infinity;
        } else {
            val = *it - a[i];
        }
        long long int x = (a[i] >= value ? a[i] : infinity);
        x = min(x, val);
        if (x == infinity) {
            cout << "NO" << endl;
            return;
        }
        value = x;
    }
    cout << "YES" << endl;
}


int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

/*
*
2
1 3
5
9 1 1000000000
3 2
1 4 3
3 4*/