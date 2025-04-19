#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    const int cnt = ranges::count(s, '<');
    const int cur = cnt + 1;
    int lo = cur - 1;
    int hi = cur + 1;

    cout << cur;

    for (const char c : s) {
        if (c == '<') {
            cout << ' ' << lo;
            --lo;
        } else {
            cout << ' ' << hi;
            ++hi;
        }
    }
    cout << '\n';

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