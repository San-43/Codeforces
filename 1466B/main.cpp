#include <bits/stdc++.h>

using ll = long long;

using namespace std;

void solve() {
    int n;
    cin >> n;
    set <int> S;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (S.count(x))
            x++;
        S.insert(x);
    }

    cout << (int) S.size() << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
