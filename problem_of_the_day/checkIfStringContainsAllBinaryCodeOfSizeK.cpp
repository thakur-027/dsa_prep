class Solution {
public:
    bool hasAllCodes(string s, int k) {

        int need = 1 << k;              // total patterns = 2^k
        vector<bool> seen(need, false);

        int mask = need - 1;
        int num = 0;
        int count = 0;

        for(int i = 0; i < s.size(); i++){

            num = ((num << 1) & mask) | (s[i] - '0');

            if(i >= k-1 && !seen[num]){
                seen[num] = true;
                count++;
                if(count == need) return true;
            }
        }

        return false;
    }
};
