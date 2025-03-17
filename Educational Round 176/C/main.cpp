#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> cub(n + 1, 0);
    for (int i = 0; i < m; i++){
        int x;
        cin >> x;
        cub[x]++;
    }

    vector<long long> sum(n + 2, 0);
    for (int x = n; x >= 1; x--){
        sum[x] = sum[x + 1] + cub[x];
    }

    long long ans = 0;

    for (int i = 1; i < n; i++)
        ans += sum[i] * sum[n-i] - sum[max(i, n-i)];


    cout << ans << "\n";
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