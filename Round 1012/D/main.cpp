#include <bits/stdc++.h>

using namespace std;
constexpr int MAX_N = 100005;
bool prime[MAX_N + 1];

void sieve() {
    fill(prime, prime + MAX_N + 1, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= MAX_N; ++i) {
        if (prime[i]) {
            for (int j = i * i; j <= MAX_N; j += i) {
                prime[j] = false;
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;

    if(n == 2){
        cout << "2 1\n";
        return;
    }

    const int bound = (n+1) / 2;
    int Q = -1;
    for (int i = bound; i >= 2; i--) {
        if(prime[i]) { Q = i; break; }
    }

    const int L = max(1, 2*Q - n);

    vector<int> perm;
    perm.push_back(Q);

    vector<pair<int,int>> pairs;
    for (int x = L; x < Q; x++){
        int y = 2 * Q - x;
        if(y >= 1 && y <= n)
            pairs.emplace_back(x,y);
    }

    ranges::sort(pairs, [](auto &a, auto &b){ return a.first > b.first; });

    for(auto &pr : pairs){
        perm.push_back(pr.first);
        perm.push_back(pr.second);
    }

    vector used(n+1, false);
    used[Q] = true;
    for(const auto &pr : pairs){
        used[pr.first] = true;
        used[pr.second] = true;
    }

    for (int i = 1; i <= n; i++){
        if(!used[i])
            perm.push_back(i);
    }

    for (int i = 0; i < n; i++){
        cout << perm[i] << (i + 1 < n ? " " : "\n");
    }

}


int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    sieve();
    while (t--) {
        solve();
    }
    return 0;
}