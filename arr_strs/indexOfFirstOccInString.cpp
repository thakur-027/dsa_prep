class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();

        // If needle is longer than haystack, it can't be contained
        if (m > n) return -1;

        // Loop through all valid starting positions in haystack
        for (int i = 0; i <= n - m; ++i) {
            int j = 0;
            while (j < m && haystack[i + j] == needle[j]) {
                j++;
            }
            // If we matched the full length of needle
            if (j == m) return i;
        }

        return -1;
    }
};
