#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        long long int x, m;
        cin >> x >> m;
        long long int count = 0;
        for (int y = 1; y <= x*10 && y <= m; y++) {
            long long int z = x^y;
            if (y != x && (y % z == 0 || x % z == 0)) {
                count +=1;
            }
        }
        cout << count << '\n';
    }
}