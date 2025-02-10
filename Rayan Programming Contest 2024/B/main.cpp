#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        string s;
        cin >> s;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int count = 1;
            if (s[i] == '0') {
                while (s[i] == '0') {
                    if (count == m) {
                        ans++;
                        int tmp = k;
                        for (; i < n && tmp > 0; i++, tmp--) {
                            s[i] = '1';
                        }
                        i--;
                    } else {
                        count++;
                        i++;
                    }
                }
            }
        }
        cout << ans << '\n';
    }
}