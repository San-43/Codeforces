#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k, p; cin >> n >> k >> p;
    int x = (abs(k)+p-1)/p;
    cout << (x<=n?x:-1) << '\n';
}

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}