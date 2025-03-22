#include <bits/stdc++.h>

using namespace std;


int mex(const vector<int>& a) {
    const unordered_set s(a.begin(), a.end());
    int mex = 0;
    while (s.contains(mex))
        mex++;
    return mex;
}


void solve() {
    int n;
    cin >> n;
    vector<int> v(n+5);
    bool tiene0 = false;
    int count0 = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        if (v[i] == 0) {
            count0++;
            tiene0 = true;
        }
    }

    if(!tiene0) {
        cout << 1 << "\n";
        cout << "1 " << n << endl;
    } else if (v[1] == 0 && v[n] == 0) {
        cout<<3<<endl;
        cout<<1<<' '<<n/2<<endl;
        cout<<2<<' '<<n-(n/2-1)<<endl;
        cout<<1<<' '<<2<<endl;
    } else if (v[1] != 0) {
        cout<<2<<endl;
        cout<<2<<' '<<n<<endl;
        cout<<1<<' '<<2<<endl;
    } else if (v[n] !=0) {
        cout<<2<<endl;
        cout<<1<<' '<<n-1<<endl;
        cout<<1<<' '<<2<<endl;
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