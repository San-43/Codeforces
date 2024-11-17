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
        int arr[n];
        vector<int> ans(n+5);
        ans.assign(n+5, 0);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            ans[arr[i]]++;
        }
        int m = n-2;
        for (int i = 0; i < n; i++) {
            if (m % arr[i] == 0) {
                if (m / arr[i] == arr[i] && ans[m / arr[i]] < 2) {
                    continue;
                }
                if(ans[m / arr[i]]) {
                    cout << arr[i] << " " << m / arr[i] << endl;
                    break;
                }
            }
        }
    }
    return 0;
}