#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> v(n);
    int par = 0;
    for(int i = 0; i < n; i++){
        long long x,y;
        cin >> x >> y;
        v[i] = x + y;
        par ^= y & 1;
    }

    ranges::sort(v);
    long long u0 = 0;
    for(int i = 0; i < n; ){
        int j = i+1;
        while(j < n && v[j] == v[i]) ++j;
        if (j - i & 1) {
            u0 = v[i];
            break;
        }
        i = j;
    }

    cout << u0 - par << " " << par << "\n";
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