#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    if(x == n) {
        for(int i = 0; i < n; i++) {
            cout << i << " ";
        }
    } else {
        for (int i = 0; i < n; i++) {
            if (i != x)
                cout << i << " ";
        }
        cout << x;
    }
    cout << '\n';
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
