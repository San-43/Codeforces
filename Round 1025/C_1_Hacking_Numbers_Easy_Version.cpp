#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#include <bits/stdc++.h>
 
using namespace std;
 
void solve () {
    long long n;
    cin >> n;
    string s;

    cout << "mul 9\n";
    cout.flush();
    cin >> s;
    if(s == "-1")
        return; 
    
    cout << "digit\n";
    cout.flush();
    cin >> s;
    if(s == "-1")
        return; 
        
    cout << "digit\n";
    cout.flush();
    cin >> s;
    if(s == "-1")
        return; 
    
    cout << "add " << (n-9) << '\n';
    cout.flush();
    cin >> s;
    if(s == "-1")
        return; 
    
    cout << "!" << '\n';
    cout.flush();
    cin >> s;
    if(s == "-1")
        return; 
};
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}