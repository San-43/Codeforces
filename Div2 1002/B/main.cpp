#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        if (n == k) {
            vector<int> b;
            for (int i = 1; i < n; i+=2) {
                b.push_back(a[i]);
            }
            b.push_back(0);
            for (int i = 1; i <= b.size(); i++) {
                if (b[i-1] != i) {
                    cout << i << '\n';
                    break;
                }
            }
        } else {
            bool flag = true;
            for (int i = 1; i < n; i++) {
                if (a[i] != 1) {
                    if (n - (i-1) >= k) {
                        cout << "1\n";
                        flag = false;
                        break;
                    }
                }
            }
            if (flag) {
                cout << "2\n";
            }
        }
    }
}