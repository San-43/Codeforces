#include <bits/stdc++.h>

using namespace std;
constexpr int MOD = 1000000007;

long long modexp(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while(exp > 0) {
        if(exp & 1)
            res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

void solve() {
    int n, x;
    cin >> n >> x;
    vector<long long> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    const long long p = modexp(2, a[x-1], MOD);

    long long q = 0;
    for (int i = 0; i < n; i++){
        q = (q + modexp(2, a[i], MOD)) % MOD;
    }

    const long long inv = modexp(q, MOD - 2, MOD);
    cout << (p * inv) % MOD << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) {
        solve();
    }
}