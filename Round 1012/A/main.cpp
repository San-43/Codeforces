#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long x, y, a;
    cin >> x >> y >> a;

    double exce = a % (x + y);
    exce += .5;
    if (exce > static_cast<double>(x) * 1.00) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}


int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}