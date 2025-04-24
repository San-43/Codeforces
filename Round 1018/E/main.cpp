#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    vector<int> a;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'B')
            a.push_back(i+1);
    }

    const int m = a.size();
    if(m == 0) {
        cout << 0 << "\n";
        return;
    }

    vector<long long> p(m);
    for(int i = 0; i < m; i++) {
        p[i] = static_cast<long long>(a[i]) - (i+1);
    }
    long long ans = 0;
    for(const auto pi : p)
        ans += pi/2;

    for(int i = 0; i < m; ) {
        if(p[i] & 1) {
            if(i+1 < m && p[i+1] & 1) {
                ans += 1;
                i += 2;
            } else {
                ans += 1;
                i += 1;
            }
        } else {
            i += 1;
        }
    }

    cout << ans << "\n";
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