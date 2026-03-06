class Solution {
private:
    bool checkEqual(int a[26], int b[26]) {
        for(int i = 0; i < 26; i++) {
            if(a[i] != b[i])
                return 0;
        }
        return 1;
    }

public:
    bool checkInclusion(string s1, string s2) {
        int count1[26] = {0};
        for(int i = 0; i < s1.length(); i++) {
            count1[s1[i] - 'a']++;
        }

        int windowSize = s1.length();
        if(s2.length() < windowSize) return 0; // important edge case

        int count2[26] = {0};
        for(int i = 0; i < windowSize; i++) {
            count2[s2[i] - 'a']++;
        }

        if(checkEqual(count1, count2))
            return 1;

        for(int i = windowSize; i < s2.length(); i++) {
            count2[s2[i] - 'a']++;
            count2[s2[i - windowSize] - 'a']--;

            if(checkEqual(count1, count2))
                return 1;
        }

        return 0; // <-- this is now outside all loops
    }
};
