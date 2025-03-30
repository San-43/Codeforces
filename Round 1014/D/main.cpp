#include <bits/stdc++.h>

using namespace std;
int initL, initI, initT;

bool ok(const int countL, const int countI, const int countT, const int n) {
    if (n % 3 != 0) return false;
    const int target = n / 3;

    return (countL == target && countI == target && countT == target);
}

bool dfs(const string &s, vector<int> &ans, const int max) {
    if (ok(initL,initI,initT, s.length())) return true;
    if (ans.size() >= max)
        return false;

    const int n = s.size();
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1])
            continue;
        for (const char c : {'L', 'I', 'T'}) {
            if (c == s[i] || c == s[i + 1])
                continue;
            string ns = s;
            ns.insert(ns.begin() + i + 1, c);
            if (c == 'I') {
                initI++;
            } else if (c == 'T') {
                initT++;
            } else if (c == 'L') {
                initL++;
            }
            ans.push_back(i + 1);
            if (dfs(ns, ans, max))
                return true;
            ans.pop_back();
            if (c == 'I') {
                initI--;
            } else if (c == 'T') {
                initT--;
            } else if (c == 'L') {
                initL--;
            }
        }
    }
    return false;
}

void solve() {
    initI = 0, initT = 0, initL =0;
    int n;
    string s;
    cin >> n >> s;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') {
            initL++;
        } else if (s[i] == 'I') {
            initI++;
        } else if (s[i] == 'T') {
            initT++;
        }
    }

    if (dfs(s, ans, 2*n)) {
        cout << ans.size() << "\n";
        for (const int i : ans) {
            cout << i << "\n";
        }
        return;
    } else {
        cout << -1 << "\n";
    }
}


int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}