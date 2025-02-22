#include <bits/stdc++.h>
using namespace std;

vector<string> gen(const int n, const vector<string>& init) {
    if(n == 0) {
        return { "*" };
    }

    const vector<string> prev = gen(n - 1, init);
    const int size = prev.size();
    vector<string> ans;

    for (int i = 0; i < 3; i++) {
        for (int r = 0; r < size; r++) {
            string row;
            for (int j = 0; j < 3; j++) {
                if (init[i][j] == '*') {
                    row += prev[r];
                } else {
                    row.append(size, '.');
                }
            }
            ans.push_back(row);
        }
    }

    return ans;
}

void solve() {
    int n;
    cin >> n;

    vector<string> init(3);
    for (int i = 0; i < 3; i++) {
        cin >> init[i];
    }

    vector<string> ans = gen(n, init);

    for (const auto& r : ans) {
        cout << r << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while(t--) {
        solve();
    }

    return 0;
}

/*
 3
***************************
*.**.**.**.**.**.**.**.**.*
***************************
***...******...******...***
*.*...*.**.*...*.**.*...*.*
***...******...******...***
***************************
*.**.**.**.**.**.**.**.**.*
***************************
*********.........*********
*.**.**.*.........*.**.**.*
*********.........*********
***...***.........***...***
*.*...*.*.........*.*...*.*
***...***.........***...***
*********.........*********
*.**.**.*.........*.**.**.*
*********.........*********
***************************
*.**.**.**.**.**.**.**.**.*
***************************
***...******...******...***
*.*...*.**.*...*.**.*...*.*
***...******...******...***
***************************
*.**.**.**.**.**.**.**.**.*
***************************
 */


