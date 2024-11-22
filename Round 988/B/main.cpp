#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        vector<int> ans(n+5);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            ans[arr[i]] += 1;
        }
        for (int i = 1; i <= n; i++) {
            if (ans[i] > 0 && (n-2) % i == 0) {
                if (ans[(n-2) / i] > 0) {
                    cout << i << " " << (n-2) / i << "\n";
                    break;
                }
            }
        }
    }
    return 0;
}