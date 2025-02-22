#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

constexpr long long MOD = 998244353;

vector<long long> Powers(int maxExp) {
    vector<long long> pow10(maxExp + 1);
    pow10[0] = 1;
    for (int i = 1; i <= maxExp; i++){
        pow10[i] = (pow10[i-1] * 10) % MOD;
    }
    return pow10;
}
void solve () {
    string A, B;
    cin >> A >> B;

    int m = A.size();
    int n = B.size();
    int total = m + n;

    vector<int> digits;
    for (const char ch : A) {
        digits.push_back(ch - '0');
    }

    for (const char ch : B) {
        digits.push_back(ch - '0');
    }

    ranges::sort(digits, greater<int>());

    vector<int> exponents;

    for (int i = 0; i < m; i++) {
        exponents.push_back(m - 1 - i);
    }

    for (int i = 0; i < n; i++) {
        exponents.push_back(n - 1 - i);
    }

    ranges::sort(exponents, greater<int>());

    const int maxExp = exponents[0];
    vector<long long> pow10 = Powers(maxExp);

    long long ans = 0;
    for (int i = 0; i < total; i++) {
        const long long coef = pow10[exponents[i]];
        ans = (ans + digits[i] * coef) % MOD;
    }

    cout << ans % MOD << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}
