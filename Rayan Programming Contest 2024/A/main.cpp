#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        if (a > b) {
            int m = b;
            for (; m <= a*b; m++) {
                if (m % a == 0 && m % b == 0) {
                    cout << m << '\n';
                    break;
                }
            }
        } else {
            int m = a;
            for (; m <= b*a; m++) {
                if (m % a == 0 && m % b == 0) {
                    cout << m << '\n';
                    break;
                }
            }
        }
    }
}