#include <bits/stdc++.h>

using namespace std;

void solve() {
    string a, b;
    cin >> a >> b;
    string tmp = a;
    for (int i = 1; i <= tmp.size(); i++) {
        ranges::rotate(tmp, tmp.begin() + 1);
        if (tmp == b) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
    while (t--) {
        solve();
    }
}