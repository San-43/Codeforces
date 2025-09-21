#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v) {
        cin >> i;
    }
    ranges::sort(v);
    vector<int> ans;
    while (v[0] != v[n-1]) {
        if (v[0] & 1) {
            v[0] = (v[0] + 1) / 2;
            v[n - 1] = (v[n - 1] + 1) / 2;
            ans.emplace_back(1);
        } else {
            v[0] = v[0] / 2;
            v[n - 1] = v[n - 1] / 2;
            ans.emplace_back(0);
        }
    }

    if (ans.size() <= n) {
        cout << ans.size() << endl;
        for (const auto &i : ans) {
            cout << i << ' ';
        }
        cout << endl;
    } else {
        cout << ans.size() << endl;
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