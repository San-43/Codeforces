#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n, k;
    cin >> n >> k;

    long long sum = 0;
    long long tmp = k-1;
    if (n % 2 == 0) {
        sum = (n + tmp-1) / tmp;
    } else {
        if (k == n) {
            cout << 1 << '\n';
            return;
        }
        sum = 1 + ((n-k + tmp-1) / tmp);
    }
    cout << sum << '\n';
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