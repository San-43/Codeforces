#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    string x;
    cin >> x;

    string result;
    for (int i = 0; i < x.length(); ++i) {
        if (x[i] >= '5') {
            if ('9' - x[i] == 0 && i == 0)
                result += '9';
            else
                result += '9' - x[i] + '0';
        }
        else
            result += x[i];
    }

    cout << result << '\n';
    return 0;
}
