#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#include <bits/stdc++.h>

using namespace std;

void solve () {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> b(n);
    for(auto &e : a) 
        cin >> e;
    int count = 0;
    for (auto &e : b) {
        cin >> e;
        if (e == -1) {
            count++;
        }
    }

    if (count == n) {
        cout << n << '\n';
    } else {
        bool ok = true;
        int tmp = 0;
        for (int i = 1; i < n; i++) {
            if (b[i] != -1 && a[i] + b[i] != tmp) {
                ok = false;
            }
        }
        
        if(ok == 1)
            cout << '1' << '\n';
        else 
            cout << '0' << '\n';
    }

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