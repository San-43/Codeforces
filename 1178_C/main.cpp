#include <bits/stdc++.h>

using ll = long long;

using namespace std;


ll binpow(ll a, ll b) {
    a %= 998244353;
    if (b == 0)
        return 1;
    ll res = binpow(a, b/2);
    if (b % 2)
        return res * res * a % 998244353;
    else
        return res * res % 998244353;
}

int main() {
    int w;
    int h;
    cin >> w >> h;

    ll x = binpow(2, w+h);

    cout << x;

    return 0;
}
