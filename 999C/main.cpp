#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n;
    int k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<pair<char, int>> V(n);
    for (int j = 0; j < n; ++j) {
        V[j] = make_pair(s[j], j);
    }

    sort(all(V));
    sort(k+all(V), [&] (const pair <char, int> &a, const pair <char, int> &b) {
        return a.second < b.second;
    });

    for (int i = k; i < n; ++i) {
        cout << V[i].first;
    }

    cout << '\n';

    return 0;
}
