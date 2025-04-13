#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<int> b(m);
    for (int i = 0; i < m; i++){
        cin >> b[i];
    }

    vector<int> c(k);
    for (int i = 0; i < k; i++){
        cin >> c[i];
    }

    vector<int> arrb(n,0);
    for (int i = 0; i + m - 1 < n; i++){
        bool flag = true;
        for (int j = 0; j < m; j++){
            if(a[i+j] != b[j]){
                flag = false;
                break;
            }
        }
        if(flag){
            arrb[i] = 1;
        }
    }

    vector<int> arrc(n, 0);
    for (int i = k - 1; i < n; i++){
        bool flag = true;
        for (int j = 0; j < k; j++){
            if(a[i - k + 1 + j] != c[j]){
                flag = false;
                break;
            }
        }
        if(flag){
            arrc[i] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << arrc[i] << " ";
    }
    vector<int> prefixC(n, 0);
    prefixC[0] = arrc[0];
    for (int i = 1; i < n; i++){
        prefixC[i] = prefixC[i - 1] + arrc[i];
    }

    long long ans = 0;
    for (int i = 0; i < n; i++){
        if(arrb[i] == 0) continue;
        const int index = max(i + m - 1, i + k - 1);
        if (index > n-1) continue;
        ans += index == 0 ? prefixC[n - 1] : prefixC[n - 1] - prefixC[index - 1];
    }

    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) {
        solve();
    }

    return 0;
}
