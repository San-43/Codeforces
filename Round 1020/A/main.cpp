#include <bits/stdc++.h>
 
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int count1 = 0;
    int count0 = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1') 
            count1++;
    }
 
    long long ans = 0;
    for(int i = 0; i < n; i++) {
        if (s[i] == '1') 
            ans += count1 - 1;
        else
            ans += count1 + 1;
    }
    cout << ans << '\n';
    
};
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}