#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    bool dp[2] = {false, false};
    dp[(a[0] == 0)] = true;

    for (int i = 1; i < n - 1; ++i) {
        bool nxt[2] = {false, false};
        for (int p = 0; p < 2; ++p)
            if (dp[p]) {
                if (a[i] == 0) {
                    if (p == 0)
                        nxt[1] = true;
                } else {
                    if (p == 1)
                        nxt[0] = nxt[1] = true;
                    else
                        nxt[0] = true;
                }
            }
        dp[0] = nxt[0];
        dp[1] = nxt[1];
    }

    cout << (dp[a.back()] ? "NO" : "YES") << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    _getch();
    return 0;
}
