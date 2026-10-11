class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        
        for (int i = 1; i <= n; ++i) {
            // Check if 1-based index i divides n
            if (n % i == 0) {
                // Convert 1-based index i to 0-based index (i - 1)
                sum += nums[i - 1] * nums[i - 1];
            }
        }
        
        return sum;
    }
};
