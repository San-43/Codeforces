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

    
    double l = v[0].first, r = v[0].first + dist(v[0].second, angle);
    double ans = 0.0;
    for(int i = 1; i < n; i++) {
        double tmp = v[i].first + dist(v[i].second, angle);

        if (v[i].first >= r) {
            ans += r - l;
            l = v[i].first;
            r = tmp;
        } else if(tmp > r) {
            ans += v[i].first - l;
            l = v[i].first;
            r = tmp;
        }
    }
    ans += r-l;
    cout << fixed << setprecision(10) <<  ans << '\n';

};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    while(t--) {
        solve();
    }
}