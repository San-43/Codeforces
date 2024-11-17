#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int m;

    cin >> m;
    for (; m > 0; --m) {
        int n;
        char c;
        cin >> n >> c;
        string s;
        cin >> s;
        s += s;
        int last = -INFINITY;
        int ans = -INFINITY;
        for (int i = s.size() - 1; i > -1; i--) {
            last++;
            if (s[i] == 'g') {
                last = 0;
            }

            if (s[i] == c) {
                ans = max(last, ans);
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
