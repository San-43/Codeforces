#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    const int a = n / (m + 1);
    const int b = n - m * k;
    const int val = min(a, b);
    vector<int> ans(n, val);
    for (int x = 0; x < val; x++){
        const int l = x;
        const int r = n - val + x;
        const int gap = r - l;
        const int step = (m != 0 ? gap / m : 0);
        for (int j = 0; j <= m; j++){
            int pos = l + j * step;
            if (pos > r) pos = r;
            ans[pos] = x;
        }
    }
    for (int i = 0; i < n; i++){
        cout << ans[i] << (i + 1 == n ? "\n" : " ");
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
