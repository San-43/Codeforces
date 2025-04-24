#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<long long> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    long long sum1 = 0;
    vector<long long> c(n);
    for (int i = 0; i < n; i++) {
        sum1 += max(a[i], b[i]);
        c[i] = min(a[i], b[i]);
    }

    ranges::sort(c, greater<long long>());
    for (int i = 0; i < k - 1; i++) {
        sum1 += c[i];
    }

    cout << sum1 + 1 << endl;
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