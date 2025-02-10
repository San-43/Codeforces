#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    for (int i = 0; i < n-1; i++) {
        if (s[i] == s[i+1]) {
            cout << 1 << '\n';
            return;
        }
    }
    cout << n << '\n';
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