#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#include <bits/stdc++.h>

using namespace std;

void solve () {
    long long a, b, c;
    cin >> a >> b >> c;
    long long su = a+b+c;
    if(su%3 != 0) {
        cout << "NO\n";
        return;
    }

    su /= 3;
    if (a > su) {
        cout << "NO\n";
        return;
    } else if (b > su) {
        cout << "NO\n";
        return;
    } else {
        c -= su - a;
        c -= su - b;
        if (c != su) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}