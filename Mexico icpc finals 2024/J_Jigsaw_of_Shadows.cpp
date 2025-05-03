#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#include <bits/stdc++.h>

using namespace std;

double dist(int x, int angle) {
    return x / tan(angle * 3.14159265 / 180);
}

void solve () {
    int n;
    int angle;
    cin >> angle >> n;
    vector<pair<int , int>> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());

    double tm = 0.0;
    double ans = dist(v[0].second, angle);
    tm = ans + v[0].first;

    for(int i = 0; i < n; i++) {
        if(tm <= v[i].first) {
            tm = dist(v[i].second, angle) + v[i].first;
            ans += dist(v[i].second, angle);
        } else if (tm <= v[i].first + dist(v[i].second, angle)) {
            ans = ans - abs(v[i].first - ans) + dist(v[i].second, angle);
            tm = dist(v[i].second, angle) + v[i].first;
        }
    }
    cout << fixed << setprecision(10) << ans << '\n';
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    while(t--) {
        solve();
    }
}