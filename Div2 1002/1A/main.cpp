#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        vector<int> a(n);
        map<int,int> mp1;
        map<int,int> mp2;
        set<int> s;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(v.begin(), v.end());
        sort(a.rbegin(), a.rend());
        for (int i = 0; i < n; i++) {
            s.insert(v[i] + a[i]);
        }

        reverse(v.begin(), v.end());
        for (int i = 0; i < n; i++) {
            s.insert(v[i] + a[i]);
        }
        if (s.size() >= 3) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}