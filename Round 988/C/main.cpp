#include <bits/stdc++.h>

using namespace std;

void SieveOfEratosthenes(int n, vector<bool> &prime)
{
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    vector prime(200005, true);
    SieveOfEratosthenes(200005, prime);
    while (t--) {
        int n;
        cin >> n;

        vector<int> ans;
        for (int i = 1; i <= n; i+=2) {
            ans.push_back(i);
        }
        bool flag = false;
        int temp = 0;
        for (int i = 2; i <= n; i+=2) {
            if(!prime[ans.back()+i]) {
                ans.push_back(i);
                temp = i;
                flag = true;
                break;
            }
        }
        if (!flag) {
            cout << "-1\n";
            continue;
        }
        for (int i = ans.back()+2; i <= n; i+=2) {
            ans.push_back(i);
        }

        for (int i = temp-2; i > 0; i-=2) {
            ans.push_back(i);
        }

        for(const int e : ans) {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}