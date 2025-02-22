#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int count = 0;
    bool flag = false;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1' && !flag) {
            count++;
            flag = true;
        } else if (s[i] == '0' && flag) {
            count++;
            flag = false;
        }
    }
    cout << count << endl;
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