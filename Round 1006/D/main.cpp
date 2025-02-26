#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    int val = 0;
    int L = 0, R = 0;

    for(int l = 0; l < n; l++){
        int curr = 0;
        for (int r = l + 1; r < n; r++){
            if(a[r] < a[l])
                curr++;
            else if(a[r] > a[l])
                curr--;

            if(curr > val){
                val = curr;
                L = l;
                R = r;
            }
        }
    }

    cout << L + 1 << " " << R + 1 << "\n";
}

int main(){
    ios::sync_with_stdio(NULL);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}