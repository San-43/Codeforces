#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    ll mn = LLONG_MAX;
    int count = 0;
    vector<long long> div;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] < mn) {
            mn = a[i];
        }
    }
    for (int i = 0; i < n; ++i) {
        if(a[i] % mn == 0 && a[i] != mn)
            div.push_back(a[i]);
        if (mn == a[i]) {
            ++count;
        }
    }
    bool flag = false;
    if(count > 1) {
        flag = true;
    } else {
        if(div.empty() || div.size() == 1) {
            flag = false;
        } else {
            long long g = div[0];
            for (int i = 1; i < div.size(); i++){
                g = gcd(g, div[i]);
            }
            if(g == mn)
                flag = true;
            else
                flag = false;
        }
    }

    cout << (flag ? "Yes" : "No") << "\n";
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}