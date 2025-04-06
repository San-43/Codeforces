#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    double area = 0.0;

    for (int i = 0; i < m; ++i) {
        string line;
        cin >> line;
        for (const char ch : line) {
            if (ch == '.') area += 1.0;
            else if (ch == '/' || ch == '\\') area += 0.5;
        }
    }

    cout << fixed << setprecision(2) << area << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
    while (t--) {
        solve();
    }
}