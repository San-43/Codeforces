#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long int x, y;
    cin >> x >> y;

    if (x & y == 0) {
        cout << 0 << '\n';
        return;
    }

    if(x == y) {
        cout << -1 << '\n';
    } else {
        cout << (1ll << 32) - max(x, y) << '\n';
    }
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