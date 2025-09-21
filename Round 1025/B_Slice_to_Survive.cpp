#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#include <bits/stdc++.h>

using namespace std;

int ceil_log2(long long x) {
    if (x <= 1) return 0;
    int fl = 63 - __builtin_clzll(x);
    if ((1LL << fl) == x) return fl;
    return fl + 1;
}

void solve() {
    long long n, m, a, b;
    cin >> n >> m >> a >> b;
    long long H = min(a, n - a + 1);
    long long W = min(b, m - b + 1);
    int resh = ceil_log2(H) + ceil_log2(m);
    int resv = ceil_log2(n) + ceil_log2(W);
    int ans = 1 + min(resh, resv);
    cout << ans << '\n';
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    cout << flush;
    system("Pause");
}