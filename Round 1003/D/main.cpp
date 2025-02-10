#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<unsigned long long int, vector<int>>> mp(n);
    unsigned long long int sum = 0;
    for (int i = 0; i < n; i++) {
        sum = 0;
        vector<int> v(m);
        for (int j = 0; j < m; j++) {
            cin >> v[j];
            sum += v[j];
        }
        mp[i] = make_pair(sum, v);
    }

    sort(mp.rbegin(), mp.rend());
    sum = 0;
    for (const auto& [s, v] : mp) {
        const int tmp1 = (n-1) * m;
        sum += s*tmp1;
        int tmp = m;
        for (const auto vv : v) {
            sum += 1LL*vv*tmp;
            tmp--;
        }
        n--;
    }
    cout << sum << endl;
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