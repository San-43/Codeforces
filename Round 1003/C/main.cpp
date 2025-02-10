#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long int n, m;
    cin >> n >> m;
    vector<long long int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long int x;
    cin >> x;

    if (is_sorted(a.begin(), a.end())) {
        cout << "YES" << endl;
        return;
    }

    long long  int value = LLONG_MIN;

    for (int i = 0; i < n; i++) {
        long long tmp = x-a[i];
        long long int l = min(a[i], tmp), r = max(a[i], tmp);

        if (l >= value) {
            value = l;
        } else if (r >= value) {
            value = r;
        } else {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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