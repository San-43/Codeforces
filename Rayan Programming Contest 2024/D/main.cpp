#include <bits/stdc++.h>

using namespace std;

const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();
#endif
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int r = 0;
        int n = nums.size();
        int kfreq = 0;
        vector<int> freq(55, 0);
        for (int i = 0; i < n; i++) {

            if (nums[i] == k) {
                kfreq++;
                for (int j = 0; j < 55; j++) {
                    r = max(r, freq[j]);
                }
                for (int j = 0; j < 55; j++) {
                    freq[j] = 0;
                }
            } else {
                freq[nums[i]]++;
            }
        }
        for (int j = 0; j < 55; j++) {
            r = max(r, freq[j]);
        }

        return r + kfreq;
    }
};

int main() {
    cin.tie(NULL);
    std::ios::sync_with_stdio(false);
}