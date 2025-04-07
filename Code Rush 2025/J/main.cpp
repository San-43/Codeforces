#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    double area = 0.0;

    for (int i = 0; i < m; ++i) {
        string line;
        cin >> line;
        bool band = false;
        for (const char ch : line) {
            if (ch == '/' || ch == '\\') {
                if (!band)
                    band = true;
                else
                    band = false;
                area += .5;
            } else if (band)
                area += 1;
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