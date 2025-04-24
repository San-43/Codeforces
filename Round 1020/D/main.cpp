#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    vector<int> Lpref(m+1, n);
    Lpref[0] = -1;
    int j = 0;
    for(int i = 1; i <= m; i++) {
        while(j < n && a[j] < b[i-1])
            j++;
        if(j < n) {
            Lpref[i] = j;
            j++;
        } else {
            Lpref[i] = n;
        }
    }

    if(Lpref[m] < n){
        cout << 0 << '\n';
        return;
    }

    vector<int> Rsuff(m+1, -1);
    Rsuff[m] = n;
    j = n-1;
    for(int i = m-1; i >= 0; i--){
        while(j >= 0 && a[j] < b[i]) j--;
        if(j >= 0){
            Rsuff[i] = j;
            j--;
        } else {
            Rsuff[i] = -1;
        }
    }

    int ans = INT32_MAX;
    for(int t = 0; t < m; t++){
        if(Lpref[t] < Rsuff[t+1]){
            ans = min(ans, b[t]);
        }
    }
    if(ans >= 1e9) ans = -1;
    cout << ans << '\n';

}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}