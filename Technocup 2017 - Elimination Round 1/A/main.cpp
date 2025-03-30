#include <bits/stdc++.h>

using namespace std;

bool flag = false;
set<long long> v;

void dfs(const long long a, const long long b) {
    if (flag) return;
    if (a == b) {
        v.insert(a);
        flag = true;
        return;
    }
    if (a > b) {
        return;
    }
    v.insert(a);
    dfs(a*2, b);
    dfs(a*10+1, b);
    if (flag) {
        return;
    }
    v.erase(a);
}

void solve() {
    long long  a, b;
    cin >> a >> b;
    dfs(a, b);
    if (flag) {
        cout << "YES" << endl;
        cout<< v.size() << endl;
        for (const auto i : v) cout << i << ' ';
        return;
    }
    cout << "NO" << endl;
}


int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}