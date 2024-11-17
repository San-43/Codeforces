#include <bits/stdc++.h>

#define all(v) (v).begin(), (v).end()

using namespace std;

void solve() {
    int x;
    cin >> x;
    vector<int> V(x);
    for (auto &e: V) {
        cin >> e;
    }

    sort(all(V));
    if (V.front() == V.back()) cout << x << "\n";
    else cout << "1\n";
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
    return 0;
}
