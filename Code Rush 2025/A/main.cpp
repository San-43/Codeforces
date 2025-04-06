#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    map<int, map<long long, set<long long>>> v;
    for (int i = 0; i < n; i++) {
        long long x, y, z;
        cin >> x >> y >> z;
        v[x][y].insert(z);
    }
    for (auto x : v) {
        cout << x.first << " " << x.second.size() << " ";
        long long count = 0;
        for (auto y : x.second) {
            count += y.second.size();
        }
        cout << count << endl;
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t = 1;
    while (t--) {
        solve();
    }
}