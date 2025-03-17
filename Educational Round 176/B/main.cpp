#include <bits/stdc++.h>

using namespace std;

vector<long long> pre(const vector<long long> &arr) {
    vector<long long> tmp = arr;

    ranges::sort(tmp, greater<>());
    vector<long long> prefix(tmp.size() + 1, 0);
    for (int i = 0; i < tmp.size(); i++) {
        prefix[i + 1] = prefix[i] + tmp[i];
    }
    return prefix;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<long long> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    long long ans = 0;
    vector<long long> a1;
    for (int i = 2; i <= n; i++) {
        a1.push_back(v[i]);
    }

    const vector<long long> prea1 = pre(a1);
    const long long candidate1 = prea1[k] + v[1];
    ans = max(ans, candidate1);

    vector<long long> a2;
    for (int i = 1; i <= n - 1; i++) {
        a2.push_back(v[i]);
    }
    const vector<long long> pre2 = pre(a2);
    long long candidate2 = pre2[k] + v[n];
    ans = max(ans, candidate2);

    for (int r = 2; r <= n - 1; r++) {
        const int lz = r - 1;
        const int rz = n - r;
        if (lz < 1 || rz < 1) { continue; }

        vector<long long> a3;
        a3.reserve(lz);
        for (int i = 1; i < r; i++) {
            a3.push_back(v[i]);
        }
        vector<long long> pre3 = pre(a3);

        vector<long long> a4;
        a4.reserve(rz);
        for (int i = r + 1; i <= n; i++) {
            a4.push_back(v[i]);
        }
        vector<long long> pre4 = pre(a4);

        for (int j = 1; j <= k - 1; j++) {
            const int ln = j;
            const int rn = k - j;
            if (ln > lz || rn > rz) { continue; }
            const long long sl = pre3[ln];
            const long long sr = pre4[rn];
            long long candidate = sl + sr + v[r];
            ans = max(ans, candidate);
        }
    }

    cout << ans << '\n';
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