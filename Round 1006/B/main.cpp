#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    const int x = ranges::count(s, '_');
    const int y = n - x;
    cout << y/2LL*((y+1)/2)*x << '\n';
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