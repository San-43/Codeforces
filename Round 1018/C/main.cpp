#include <bits/stdc++.h>

using namespace std;

long long dp(const bool flag, const int n, const vector<vector<long long>>& grid, const vector<long long>& cost) {
    long long dp0 = 0, dp1 = cost[0];

    for (int i = 1; i < n; i++) {
        long long ndp0 = LLONG_MAX, ndp1 = LLONG_MAX;
        for (int prev = 0; prev < 2; prev++) {
            const long long dp_prev = (prev == 0 ? dp0 : dp1);
            if (dp_prev >= LLONG_MAX) continue;
            for (int cur = 0; cur < 2; cur++) {
                bool ok = true;
                for (int j = 0; j < n; j++) {
                    const long long d = flag ? grid[i-1][j] - grid[i][j] : grid[j][i-1] - grid[j][i];
                    if (abs(d) <= 1 && cur - prev == d) {
                        ok = false;
                        break;
                    }
                }
                if (!ok) continue;
                long long cand = dp_prev + (cur ? cost[i] : 0);
                if (cur == 0)
                    ndp0 = min(ndp0, cand);
                else
                    ndp1 = min(ndp1, cand);
            }
        }
        dp0 = ndp0;
        dp1 = ndp1;
    }

    return min(dp0, dp1);
}
void solve() {
    int n;
    cin >> n;
    vector<vector<long long>> grid(n, vector<long long>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    vector<long long> a(n);
    vector<long long> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    const long long r = dp(true,  n, grid, a);
    const long long c = dp(false, n, grid, b);

    r >= LLONG_MAX || c >= LLONG_MAX ? cout << -1 << endl : cout << r + c << endl;

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