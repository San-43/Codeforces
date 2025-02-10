#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--) {
        int n, k;
        cin>>n>>k;
        vector<int> v(n);

        if (k > n || (k == 1 && n > 1)) {
            cout<<"NO"<<'\n';
        } else {
            cout<<"YES"<<'\n';
            for (int i = 0; i < k; i++) {
                for (int j = 0; j < n; j++) {
                    cout<< (i + j) % n + 1 << " ";
                }
                cout << '\n';
            }
        }
    }
}