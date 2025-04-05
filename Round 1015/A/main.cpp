#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    if(n % 2 == 0){
        cout << -1 << "\n";
    } else {

        cout << n;
        for(int i = 1; i < n; i++){
            cout << " " << i;
        }
        cout << "\n";
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
}