#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    bool flag = true;
    for (int i = 1; i < n && flag; i++) {
        for (int j = 1; j < m; j++) {
            if (grid[i][j] == '1') {
                int tmpi = i;
                int tmpj = j;
                bool fl1 = true;
                bool fl2 = true;
                while (tmpi >= 0) {
                    if (grid[tmpi][tmpj] == '0') {
                        fl1 = false;
                        break;
                    }
                    tmpi = tmpi - 1;
                }
                tmpi = i;
                while (tmpj >= 0) {
                    if (grid[tmpi][tmpj] == '0') {
                        fl2 = false;
                        break;
                    }
                    tmpj = tmpj - 1;
                }
                if (fl1==false && fl2==false) {
                    flag = false;
                    break;
                }
            }
        }
    }

    cout << (flag ? "Yes" : "No") << "\n";


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