#include <bits/stdc++.h>

using ll = long long;

using namespace std;

ll gauss (ll n) {
    return n*(n+1)/2;
}

int main() {
    ll n;
    cin >> n;

    ll aux = 0;
    ll ans = 0;
    while (n > 0) {
        ans++;
        if (gauss(aux + 1) <= n) {
            aux++;
            n -= aux;
        } else if (gauss(aux) <= n) {
            n -= aux;
        } else {
            aux--;
            n -= aux;
        }
    }

    cout << ans << '\n';
    return 0;
}
