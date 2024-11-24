#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v;
        for (int i = 1; i <= n; i++) {
            v.push_back(i + (i - 1));
        }
        for (auto &ele : v) {
            cout << ele << " ";
        }
        cout << '\n';
    }
}