#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct PairData {
    int idx;
    int a, b;
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    vector<int> self;
    map<pair<int,int>, vector<int>> pos0, pos1;

    bool ok = true;

    for (int i = 0; i < n; i++){
        if(a[i] == b[i]){
            self.push_back(i);
        } else {
            pair<int,int> key = {min(a[i], b[i]), max(a[i], b[i])};
            if(a[i] < b[i]) {
                pos0[key].push_back(i);
            } else {
                pos1[key].push_back(i);
            }
        }
    }
    if(n % 2 == 0){
        if(!self.empty()){
            ok = false;
        }
    } else {
        if(self.size() != 1){
            ok = false;
        }
    }
    vector<pair<int,int>> mirrorPairs;
    for(auto &p: pos0){
        auto key = p.first;
        int cnt0 = p.second.size();
        int cnt1 = pos1[key].size();
        if(cnt0 != cnt1){
            ok = false;
            break;
        }
        for (int k = 0; k < cnt0; k++){
            mirrorPairs.emplace_back(p.second[k], pos1[key][k]);
        }
    }
    if(mirrorPairs.size() * 2 + self.size() != (size_t)n){
        ok = false;
    }
    if(!ok){
        cout << -1 << "\n";
        return;
    }

    vector<int> P(n, -1);
    int left = 0, right = n - 1;
    for(auto &pr : mirrorPairs){
        P[left++] = pr.first;
        P[right--] = pr.second;
    }

    if(n % 2 == 1){
        P[left] = self[0];
    }

    vector<int> cur(n);
    for (int i = 0; i < n; i++) cur[i] = i;

    vector<int> pos(n);
    for (int i = 0; i < n; i++){
        pos[cur[i]] = i;
    }
    vector<pair<int,int>> ops;
    for (int i = 0; i < n; i++){
        if(cur[i] == P[i]) continue;
        int j = pos[P[i]];
        swap(cur[i], cur[j]);
        pos[cur[i]] = i;
        pos[cur[j]] = j;
        ops.emplace_back(i+1, j+1);
    }
    if(ops.size() > static_cast<size_t>(n)){
            cout << -1 << "\n";
    } else {
        cout << ops.size() << "\n";
        for(auto &op : ops){
            cout << op.first << " " << op.second << "\n";
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
