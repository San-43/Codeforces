#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> odd;
    vector<int> even;
    vector<long long> v(n);

    long long sum = 0;
    long long maxa = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
        maxa = max(maxa, v[i]);
        if (v[i] % 2 == 0) {
            even.push_back(v[i]);
        } else {
            odd.push_back(v[i]);
        }
    }

    if (odd.empty() || even.empty()) {
        cout << maxa << endl;
        return;
    }
    long long tmp1 = sum - (odd.size() - 1);

    long long ans = max({maxa, tmp1});
    cout << ans << endl;
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