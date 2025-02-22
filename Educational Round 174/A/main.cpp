#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            mp[arr[i][j]] = 1;
        }
    }
    int rest = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i+1 < n) {
                if (arr[i][j] == arr[i+1][j]) {
                    mp[arr[i][j]] = 2;
                    rest = 2;
                }
            }
            if (j+1 < m) {
                if (arr[i][j] == arr[i][j+1]) {
                    mp[arr[i][j]] = 2;
                    rest = 2;
                }
            }
        }
    }
    int ans = 0;
    for (auto& p : mp) {
        ans += p.second;
    }
    cout << ans - rest << endl;
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