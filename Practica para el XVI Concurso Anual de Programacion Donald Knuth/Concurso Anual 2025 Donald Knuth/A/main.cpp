#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    long long dp_pos = 0, dp_neg = 0;

    for (int i = 0; i < n; i++){
        long long x;
        cin >> x;
        if (x > 0) {
            dp_pos = max({dp_pos, x, dp_neg + x});
        } else {
            dp_neg = max({dp_neg, x, dp_pos + x});
        }
    }

    const long long ans = max({0LL, dp_pos, dp_neg});

    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while(t--) {
        solve();
    }

    return 0;
}
