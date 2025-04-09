#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> b(1001, 0);
    int count = 0;
    int ans = 1;
    for (int i = 0; i < n; i++) {
        if (b[a[i]] == 0) {
            count++;
        }

        b[a[i]]++;

        if (count > k) {
            ans++;
            b.assign(1001, 0);
            b[a[i]] = 1;
            count = 1;
        }
    }

    cout << ans << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) {
        solve();
    }
}