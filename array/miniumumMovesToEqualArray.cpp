class Solution {
public:
    int minMoves(vector<int>& nums) {
        int max_val = nums[0];
        
        // Find the maximum element in the array
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > max_val) {
                max_val = nums[i];
            }
        }
        
        int moves = 0;
        
        // Calculate the difference between the maximum element and each element
        for (int i = 0; i < nums.size(); ++i) {
            moves += (max_val - nums[i]);
        }
        
        return moves;
    }
};
