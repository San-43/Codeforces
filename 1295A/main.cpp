#include <iostream>

using namespace std;

void solve() {
    int x;
    cin >> x;
    if (x % 2 == 0) {
        int i = x/2;
        while(i--)
            cout << '1';
        cout << '\n';
    } else {
        cout << '7';
        int i = x/2 - 1;
        while (i--)
            cout << '1';
        cout << '\n';
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
