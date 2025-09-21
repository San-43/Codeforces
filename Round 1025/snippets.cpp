long substrCount(int n, string s) {
    vector<int> v(n, 0);
    int ans = 0;
    int j = 0;

    for (int i = 0; i < n; i = j) {
        j = i + 1;
        int c = 1;
        while(j < n && s[i] == s[j]) {
            j++;
            c++;
        }
        ans += (c * (c + 1)) >> 1; //FÓRMULA PARA NÚMERO DE SUBSTRINGS CON CARACTERES IGUALES
        v[i] = c;
        
    }

    for (int i = 1; i < n - 1; i++) {
        if (s[i] == s[i - 1]) {
            v[i] = v[i - 1];
        }

        if (s[i - 1] == s[i + 1] && s[i] != s[i - 1]) {
            ans += min(v[i - 1], v[i + 1]);
        }
    }
    cout << ans << '\n';
    return ans;
}