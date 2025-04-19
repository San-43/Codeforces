#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            char ch;
            cin >> ch;
            grid[i][j] = ch == 'B';
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        const int r = i == 0 ? 0 : grid[i][0] ^ grid[0][0];
        for (int j = 0; j < m; j++) {
            if ((grid[i][j] ^ r ^ grid[0][j]) != 0) {
                count++;
            }
        }
    }

    cout << count << "\n";
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
