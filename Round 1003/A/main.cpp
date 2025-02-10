#include <bits/stdc++.h>



using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    if (n == 2) {
        cout << "i" << '\n';
        return;
    }
    s.pop_back();
    s.pop_back();
    s += 'i';
    cout << s << '\n';
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