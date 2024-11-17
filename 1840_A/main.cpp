#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        char aux = s[0];
        cout << s[0];
        for (int i = 1; i < n; ++i) {
            if (s[i] == aux && i != n-1) {
                cout << s[++i];
                aux = s[i];
            }
        }
        cout << '\n';
    }
    return 0;
}
