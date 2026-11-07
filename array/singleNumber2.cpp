class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0;
        int twos = 0;
        
        for (int num : nums) {
            // Add num to ones if it's not in twos
            ones = (ones ^ num) & ~twos;
            
            // Add num to twos if it's not in ones
            twos = (twos ^ num) & ~ones;
        }
        
        return ones;
    }
};