#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#include <bits/stdc++.h>

using namespace std;

void solve () {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(s.back() == s[0]) {
        if(s[0] == 'A')
            cout << "Alice" << '\n';
        else 
            cout << "Bob\n";
        return;
    }
    if(s.back() == s[n-2]) {
        if(s.back() == 'A')
            cout << "Alice" << '\n';
        else 
            cout << "Bob\n";
        return;
    }
    
    if(s.back() == 'A') {
        cout << "Bob\n";
        return;
    } else {
        int cnt = 0;
        for(auto x: s) {
            if(x == 'B')
                cnt++;
        }
        if(cnt >= 2) {
            cout << "Bob\n";
        } else
            cout << "Alice\n";
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