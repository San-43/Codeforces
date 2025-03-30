#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    const int par = n/2;
    const int impar = (n+1)/2;
    int sum1 = 0, sum2 = 0;

    for (int i = 0; i < n; i++) {
        if (i%2 == 0 && a[i] == '0') {
            sum1++;
        } else {
            if (a[i] == '0') {
                sum2++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (i%2 == 1 && b[i] == '0') {
            sum1++;
        } else {
            if (b[i] == '0') {
                sum2++;
            }
        }
    }

    if (sum1 >= impar && sum2 >= par ) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";

}


int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}