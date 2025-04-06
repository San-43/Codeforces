#include <bits/stdc++.h>

using namespace std;

void solve() {
    string a;
    long long sumtotal = 0;
    string ans;
    cin >> a;
    for (int i = 0; i < a.length(); i++) {
        sumtotal += a[i];
    }
    long long tmp = 0;
    for (int i = 0; i < a.length(); i++) {
        ans += a[i];
        tmp += a[i];
        if (tmp * (a.length() / ans.length()) == sumtotal) {
            cout << ans << endl;
            return;
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
    while (t--) {
        solve();
    }
}