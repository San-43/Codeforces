#include <bits/stdc++.h>

using ll = long long;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int r, c, k;
    cin >> r >> c >> k;
    vector<int> V(r, 0);
    for (int i = 0; i < c; ++i) {
        int x;
        cin >> x;
        V[x-1]++;
    }
    sort(V.begin(), V.end());
    reverse(V.begin(), V.end());

    ll ans = 0;
    if (k < r) {
        cout << c << '\n';
    } else {
        for (int i = 0; i < r; ++i) {
            ans += V[i];
        }
    }

    cout << ans << '\n';
    return 0;
}