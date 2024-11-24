#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        if (s.length() == 1) {
            cout << "-1" << '\n';
            continue;
        }
        bool band = false;
        for (int i = 0; i < s.length()-1; i++) {
            if (s[i] == s[i+1]) {
                band = true;
                cout << s.substr(i, 2) << '\n';
                break;
            }
        }
        for (int i = 0; i < s.length()-2; i++) {
            if (!band && s[i] != s[i+2]) {
                cout << s.substr(i, 3) << '\n';
                band = true;
                break;
            }
        }
        if (!band) {
            cout << "-1" << '\n';
        }
    }
}