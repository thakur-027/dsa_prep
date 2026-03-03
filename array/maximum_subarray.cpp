class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int n = nums.size();

        int currSum = 0;
        int maxSum = INT_MIN;

        for(int i = 0; i < n; i++) {

            // Step 1: Add current element
            currSum = currSum + nums[i];

            // Step 2: Update maximum sum found so far
            if(currSum > maxSum) {
                maxSum = currSum;
            }

            // Step 3: If current sum becomes negative,
            // reset it because it will only reduce future sums
            if(currSum < 0) {
                currSum = 0;
            }
        }

        return maxSum;
    }
};
