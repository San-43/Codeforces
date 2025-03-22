#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (n == 1) {
        cout << "NO\n";
        return;
    }
    string r = s;
    reverse(r.begin(), r.end());
    if (s < r) {
        cout << "YES\n";
        return;
    }
    if (k == 0) {
        cout << "NO\n";
        return;
    }
    bool flag = true;
    for (int i = 1; i < n; i++) {
        if (s[i] != s[0]) {
            flag = false;
            break;
        }
    }
    if (flag) {
        cout << "No\n";
        return;
    } else {
        cout << "Yes\n";
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