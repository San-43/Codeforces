#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int x;
    cin >> x;

    for (; x > 0; x--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (auto &e : v) cin >> e;

        string s;
        cin >> s;

        vector<vector<int>> places(51);
        for (int i = 0; i < n; ++i) {
            places[v[i]].push_back(i);
        }

        bool ok = true;

        for (int i = 1; i < 51; ++i) {
            if (!places[i].empty()) {
                char first = s[places[i][0]];
                for (int j = 0; j < places[i].size(); ++j) {
                    if (s[places[i][j]] != first) {
                        ok = false;
                        break;
                    }
                }
                if (!ok) break;
            }
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}
