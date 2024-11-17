#include <bits/stdc++.h>

using namespace std;


void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n+1];
        int score = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        vector<bool> cub(n+5);
        cub.assign(n+5, false);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[i] == arr[j] && !cub[i] && !cub[j]) {
                    cub[i] = true; cub[j] = true;
                    score++;
                    break;
                }
            }
        }
        cout << score << '\n';
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
